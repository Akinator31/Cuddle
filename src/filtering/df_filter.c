/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_filter.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "dataframe.h"
#include "errors.h"

static bool filter_row(
    void *content,
    size_t current_row,
    bool (*filter_func)(void *),
    column_type_t type)
{
    bool result = false;

    if (type == INT || type == UINT)
        result = filter_func(&((int *)(content))[current_row]);
    if (type == BOOL)
        result = filter_func(&((bool *)(content))[current_row]);
    if (type == FLOAT)
        result = filter_func(&((double *)(content))[current_row]);
    return result;
}

static dataframe_t *filter_rows(
    dataframe_t *data,
    dataframe_t *new,
    bool (*filter_func)(void *),
    ssize_t col)
{
    size_t current_row = 0;
    bool result = false;
    column_t column = data->columns[col];

    for (size_t i = 0; i < data->nb_rows; i++) {
        if (column.type == STRING)
            result = filter_func(column.content_strings[i]);
        else
            result = filter_row(column.content, i, filter_func, column.type);
        if (result) {
            copy_row(data, new, i, current_row);
            current_row++;
            }
    }
    new->nb_rows = current_row;
    return new;
}

dataframe_t *df_filter(
    dataframe_t *data,
    const char *column,
    bool (*filter_func)(void *))
{
    dataframe_t *new = NULL;
    ssize_t col = 0;

    if (!data)
        return NULL;
    new = create_dataframe(data->nb_rows, data->nb_columns, data->delimiter);
    for (size_t i = 0; i < data->nb_columns; i++) {
        new->columns[i].content = malloc(sizeof(void *) * data->nb_rows);
        new->columns[i].name = strdup(data->columns[i].name);
    }
    col = find_column(data, column);
    if (col == -1)
        return write_error(COLUMN_NOT_FOUND, column, -1);
    filter_rows(data, new, filter_func, col);
    return new;
}
