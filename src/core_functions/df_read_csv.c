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
#include "errors.h"
#include "lib.h"
#include "garbage_collector.h"

static column_t *create_column(char *name)
{
    column_t *column = NULL;

    column = my_calloc(1, sizeof(column_t));
    column->name = name;
    column->column_content = my_calloc(1, sizeof(char *) * 2);
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

    data = my_calloc(1, sizeof(dataframe_t));
    data->nb_rows = 0;
    if (getlinex(&content, &line_size, fptr) == -1 || !content)
        return write_error(BAD_LINE, EMPTY_STRING, (long)data->nb_rows);
    line_content = line_to_row(content, separators);
    data->nb_columns = str_array_len(line_content);
    data->columns = my_calloc(1, sizeof(column_t *) * data->nb_columns);
    for (size_t i = 0; line_content[i]; i++)
        data->columns[i] = create_column(line_content[i]);
    free(content);
    return data;
}

static dataframe_t *fill_columns(
    char **content,
    dataframe_t *data)
{
    static size_t col_size = 1;
    bool realloc_columns_content = false;

    if (str_array_len(content) != data->nb_columns)
        return write_error(UNEVEN_LINES, EMPTY_STRING, (long)data->nb_rows);
    if (data->nb_rows >= col_size - 1) {
        col_size <<= 1;
        realloc_columns_content = true;
    }
    for (size_t i = 0; i < data->nb_columns; i++) {
        if (realloc_columns_content)
            data->columns[i]->column_content = my_realloc(
                data->columns[i]->column_content, 8 * (col_size + 1),
                8 * ((col_size >> 1) + 1));
        data->columns[i]->column_content[data->nb_rows] =
            my_strdup(content[i]);
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
    while (getlinex(&content, &line_size, fptr) != -1 && content) {
        line_content = line_to_row(content, separators);
        if (!fill_columns(line_content, data))
            return NULL;
        data->nb_rows++;
    }
    if (content)
        free(content);
    return data;
}

static FILE *check_file(const char *filename)
{
    struct stat stat_buffer;
    FILE *fptr = NULL;

    if (!strchr(filename, '.') || strcmp(strchr(filename, '.'), ".csv"))
        write_error(NOT_CSV, filename, -1);
    if (stat(filename, &stat_buffer) == -1) {
        perror(strerror(errno));
        return NULL;
    }
    if (stat_buffer.st_size == 0)
        return write_error(EMPTY_FILE, filename, -1);
    fptr = fopen(filename, READ_ONLY);
    if (!fptr)
        perror(strerror(errno));
    return fptr;
}

dataframe_t *df_read_csv(
    const char *filename,
    const char *separators)
{
    FILE *fptr = NULL;
    dataframe_t *data = NULL;

    fptr = check_file(filename);
    if (!fptr)
        return lib_exit();
    data = read_file(fptr, separators);
    if (!data)
        return lib_exit();
    return data;
}
