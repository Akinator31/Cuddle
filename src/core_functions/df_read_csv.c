/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_read_csv
*/

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "cuddle.h"
#include "dataframe.h"
#include "lib.h"

static column_t *create_column(char *name)
{
    column_t *column = NULL;

    column = calloc(1, sizeof(column_t));
    column->name = name;
    column->column_content = calloc(1, sizeof(char *) * 2);
    column->column_content[0] = NULL;
    column->column_content[1] = NULL;
    column->type = UNDEFINED;
    return column;
}

static dataframe_t *create_dataframe(
    FILE *fptr,
    const char *separators)
{
    dataframe_t *data = NULL;
    char *content = NULL;
    char **line_content = NULL;
    size_t line_size = 0;

    data = calloc(1, sizeof(dataframe_t));
    data->nb_rows = 0;
    if (getline(&content, &line_size, fptr) == -1 || !content)
        return NULL;
    line_content = str_to_word_array(content, separators);
    data->nb_columns = str_array_len(line_content);
    data->columns = calloc(1, sizeof(column_t *) * data->nb_columns);
    for (size_t i = 0; line_content[i]; i++)
        data->columns[i] = create_column(line_content[i]);
    free(content);
    return data;
}

static dataframe_t *fill_columns(
    char **content,
    dataframe_t *data)
{
    static size_t column_size = 1;
    bool realloc_columns_content = false;

    if (str_array_len(content) != data->nb_columns)
        return NULL;
    if (data->nb_rows >= column_size - 1) {
        column_size <<= 1;
        realloc_columns_content = true;
    }
    for (size_t i = 0; i < data->nb_columns; i++) {
        if (realloc_columns_content)
            data->columns[i]->column_content = realloc(
                data->columns[i]->column_content,
                sizeof(char *) * (column_size + 1));
        data->columns[i]->column_content[i] = strdup(content[i]);
    }
    return data;
}

static dataframe_t *read_file(
    FILE *fptr,
    const char *separators)
{
    char *content = NULL;
    char **line_content = NULL;
    size_t line_size = 0;
    dataframe_t *data = NULL;

    data = create_dataframe(fptr, separators);
    if (!data)
        return NULL;
    while (getline(&content, &line_size, fptr) != -1 && content) {
        content[strlen(content) - 1] = 0;
        line_content = str_to_word_array(content, separators);
        if (!fill_columns(line_content, data))
            return NULL;
        data->nb_rows++;
    }
    if (content)
        free(content);
    return data;
}

static void check_file(const char *filename)
{
    struct stat stat_buffer;

    if (!strchr(filename, '.') || strcmp(strchr(filename, '.'), ".csv"))
        puts("Not a csv");
    if (stat(filename, &stat_buffer) == -1)
        perror(strerror(errno));
    if (stat_buffer.st_size == 0)
        puts("Empty file");
}

dataframe_t *df_read_csv(
    const char *filename,
    const char *separators)
{
    FILE *fptr = NULL;
    dataframe_t *data = NULL;

    check_file(filename);
    fptr = fopen(filename, READ_ONLY);
    if (!fptr) {
        perror(strerror(errno));
        return NULL;
    }
    data = read_file(fptr, separators);
    if (!data)
        return NULL;
    return data;
}
