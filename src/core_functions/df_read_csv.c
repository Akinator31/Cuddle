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

static column_t *create_column(const char *name)
{
    column_t *column = NULL;

    column = my_calloc(1, sizeof(column_t));
    column->name = my_strdup(name);
    column->content_strings = my_calloc(1, sizeof(char *) * 2);
    column->content_strings[0] = NULL;
    column->content_strings[1] = NULL;
    column->content = NULL;
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
        return write_error(BAD_LINE, EMPTY_STRING, (long)data->nb_rows + 2);
    line_content = line_to_row(content, separators, &data->nb_columns);
    data->columns = my_calloc(1, sizeof(column_t *) * data->nb_columns);
    for (size_t i = 0; line_content[i]; i++)
        data->columns[i] = create_column(line_content[i]);
    free(content);
    return data;
}

static column_t *increase_column_size(
    column_t *column,
    size_t col_size)
{
    size_t realloc_size = 0;
    size_t old_size = 0;

    realloc_size = sizeof(char *) * (col_size + 1);
    old_size = sizeof(char *) * ((col_size >> 1) + 1);
    column->content_strings =
        my_realloc(column->content_strings, realloc_size, old_size);
    return column;
}

static dataframe_t *fill_columns(
    char **content,
    dataframe_t *data,
    const char *filename,
    size_t column_count)
{
    static size_t col_size = 1;
    bool realloc_columns_content = false;

    if (column_count != data->nb_columns)
        return write_error(UNEVEN_LINES, filename, (long)data->nb_rows + 2);
    if (data->nb_rows >= col_size - 1) {
        col_size <<= 1;
        realloc_columns_content = true;
    }
    for (size_t i = 0; i < data->nb_columns; i++) {
        if (realloc_columns_content)
            increase_column_size(data->columns[i], col_size);
        data->columns[i]->content_strings[data->nb_rows] =
            my_strdup(content[i]);
    }
    return data;
}

static dataframe_t *read_file(
    FILE *fptr,
    const char *separators,
    const char *filename)
{
    char *content = NULL;
    char **line_content = NULL;
    dataframe_t *data = NULL;
    size_t line_size = 0;
    size_t column_count = 0;

    data = create_dataframe(fptr, separators);
    if (!data)
        return NULL;
    while (getlinex(&content, &line_size, fptr) != -1 && content) {
        line_content = line_to_row(content, separators, &column_count);
        if (!fill_columns(line_content, data, filename, column_count)) {
            free(content);
            return NULL;
        }
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
    if (!separators)
        separators = ",";
    data = read_file(fptr, separators, filename);
    if (!data)
        return lib_exit();
    resolve_types(data);
    return data;
}
