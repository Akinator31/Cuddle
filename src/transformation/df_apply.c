/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_apply.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataframe.h"
#include "errors.h"
#include "utils.h"

column_t *modify_string(
    column_t *column,
    size_t i,
    column_type_t type)
{
    if (type == STRING)
        return column;
    free(column->content_strings[i]);
    if (type == INT || type == UINT)
        column->content_strings[i] =
            content_to_str(&((int *)(column->content))[i], type);
    if (type == FLOAT)
        column->content_strings[i] =
            content_to_str(&((double *)(column->content))[i], type);
    if (type == BOOL)
        column->content_strings[i] =
            content_to_str(&((bool *)(column->content))[i], type);
    return column;
}

static column_t *apply_to_column(
    column_t *column,
    void *(*func)(void *value),
    size_t nb_rows)
{
    void *content = column->content;

    for (size_t i = 0; i < nb_rows; i++) {
        if (column->type == INT || column->type == UINT)
            ((int *)(content))[i] = *(int *)func(&((int *)(content))[i]);
        if (column->type == FLOAT)
            ((double *)(content))[i] =
                *(double *)func(&((double *)(content))[i]);
        if (column->type == BOOL)
            ((bool *)(content))[i] = *(bool *)func(&((bool *)(content))[i]);
        if (column->type == STRING)
            column->content_strings[i] =
                (char *)func(column->content_strings[i]);
        modify_string(column, i, column->type);
    }
    return column;
}

dataframe_t *df_apply(
    dataframe_t *data,
    const char *column,
    void *(*apply_func)(void *value))
{
    dataframe_t *new_data = NULL;
    ssize_t col = 0;

    if (!data)
        return write_error(NO_DATAFRAME, NULL, -1);
    if (!apply_func)
        return write_error(APPLY_FUNC_NULL, NULL, -1);
    col = find_column(data, column);
    if (col == -1)
        return write_error(COLUMN_NOT_FOUND, column, -1);
    new_data = create_dataframe(data->nb_rows,
        data->nb_columns, data->delimiter);
    copy_columns(data, new_data);
    apply_to_column(&(new_data->columns[col]), apply_func, data->nb_rows);
    new_data->nb_rows = data->nb_rows;
    new_data->nb_columns = data->nb_columns;
    return new_data;
}
