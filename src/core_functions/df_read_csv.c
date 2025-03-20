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
#include "errors.h"
#include "lib.h"
#include "utils.h"

static void check_duplicate_column_names(char **names)
{
    for (size_t i = 0; names[i + 1]; i++)
        if (str_in_array(names[i], &names[i + 1]))
            write_error(DUPLICATE_COL_NAME, names[i], -1);
}

static dataframe_t *fill_dataframe(
    FILE *fptr,
    const char *separators)
{
    dataframe_t *data = NULL;
    char *content = NULL;
    char **line_content = NULL;
    size_t columns_count = 0;

    if (getlinex(&content, fptr) == -1 || !content)
        return write_error(BAD_LINE, EMPTY_STRING, 1);
    line_content = line_to_row(content, separators, &columns_count);
    data = create_dataframe(32, columns_count, (char *)separators);
    data->nb_rows = 0;
    for (size_t i = 0; i < columns_count; i++)
        data->columns[i].name = strdup(line_content[i]);
    check_duplicate_column_names(line_content);
    free_str_array(line_content);
    data->nb_columns = columns_count;
    free(content);
    return data;
}

static column_t *increase_columns_content_size(
    column_t *column_array,
    size_t col_size,
    size_t col_count)
{
    for (size_t i = 0; i < col_count; i++)
        column_array[i].content_strings = realloc(
            column_array[i].content_strings, sizeof(char *) * (col_size));
    return column_array;
}

static dataframe_t *fill_columns(
    char **content,
    dataframe_t *data,
    const char *filename,
    size_t column_count)
{
    static size_t col_size = 32;

    if (column_count != data->nb_columns)
        return write_error(UNEVEN_LINES, filename, (long)data->nb_rows + 2);
    if (data->nb_rows >= col_size - 1) {
        col_size <<= 1;
        increase_columns_content_size(data->columns, col_size, column_count);
    }
    for (size_t i = 0; i < data->nb_columns; i++) {
        data->columns[i].content_strings[data->nb_rows] =
            strdup(content[i]);
    }
    return data;
}

static void check_content(char *content)
{
    if (content)
        free(content);
}

static dataframe_t *convert_and_fill(
    char *content,
    const char *separators,
    dataframe_t *data,
    const char *filename)
{
    size_t column_count = 0;
    char **line_content = NULL;

    line_content = line_to_row(content, separators, &column_count);
    if (!fill_columns(line_content, data, filename, column_count)) {
        check_content(content);
        return free_str_array(line_content);
    }
    free_str_array(line_content);
    return data;
}

static dataframe_t *read_file(
    FILE *fptr,
    const char *separators,
    const char *filename)
{
    char *content = NULL;
    dataframe_t *data = NULL;

    data = fill_dataframe(fptr, separators);
    if (!data)
        return NULL;
    while (getlinex(&content, fptr) != -1 && content) {
        if (content[0] == '\0')
            continue;
        if (!convert_and_fill(content, separators, data, filename))
            return NULL;
        data->nb_rows++;
        check_content(content);
    }
    check_content(content);
    return data;
}

static FILE *check_file(const char *filename)
{
    struct stat stat_buffer;
    FILE *fptr = NULL;

    if (strcmp(".csv", strrchr(filename, '.')))
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

// Optimize by reading big chunks of the file and then some kind of strok
// Further optimize by multi-threading
dataframe_t *df_read_csv(
    const char *filename,
    const char *separators)
{
    FILE *fptr = NULL;
    dataframe_t *data = NULL;

    fptr = check_file(filename);
    if (!fptr)
        return NULL;
    if (!separators || separators[0] == '\0')
        separators = ",";
    data = read_file(fptr, separators, filename);
    if (!data) {
        fclose(fptr);
        return NULL;
    }
    resolve_types(data);
    fclose(fptr);
    return data;
}
