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
#include "cuddle.h"
#include "dataframe.h"
#include "lib.h"

static column_t *create_column(char *name)
{
    column_t *column = NULL;

    column = calloc(1, sizeof(column_t));
    column->name = name;
    column->column_content = NULL;
    column->type = UNDEFINED;
}


static dataframe_t *create_dataframe(FILE *fptr, const char *separators)
{
    dataframe_t *data = NULL;
    char *content = NULL;
    char **line_content = NULL;
    size_t line_size = 0;

    data = calloc(1, sizeof(dataframe_t));
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

static dataframe_t *fill_columns(char **content, dataframe_t *data)
{
    if (str_array_len(content) != data->nb_columns)
        return NULL;
}

static dataframe_t *read_file(FILE *fptr, const char *separators)
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

dataframe_t *df_read_csv(const char *filename, const char *separators)
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
