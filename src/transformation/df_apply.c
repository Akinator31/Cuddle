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

static column_t *apply_to_column(
    column_t *column_ptr,
    void *(*apply_func)(void *value),
    size_t nb_rows)
{
    column_t column = *column_ptr;

    for (size_t i = 0; i < nb_rows; i++) {
        if (column.type == INT || column.type == UINT)
            ((int *)(column.content))[i] =
                *(int *)apply_func(&((int *)(column.content))[i]);
        if (column.type == FLOAT)
            ((double *)(column.content))[i] =
                *(double *)apply_func(&((double *)(column.content))[i]);
        if (column.type == BOOL)
            ((bool *)(column.content))[i] =
                *(bool *)apply_func(&((bool *)(column.content))[i]);
        if (column.type == STRING)
            ((char *)(column.content))[i] =
                *(char *)apply_func(&((char *)(column.content))[i]);
    }
    return column_ptr;
}

dataframe_t *df_apply(
    dataframe_t *data,
    const char *column,
    void *(*apply_func)(void *value))
{
    dataframe_t *new_data = NULL;
    ssize_t col = 0;

    new_data = create_dataframe(data->nb_rows, data->nb_columns);
    col = find_column(data, column);
    if (col == -1)
        return write_error(COLUMN_NOT_FOUND, column, -1);
    for (size_t i = 0; i < data->nb_columns; i++)
        copy_column_content(&data->columns[i],
            &new_data->columns[i], data->nb_rows);
    apply_to_column(&(new_data->columns[col]), apply_func, data->nb_rows);
    new_data->nb_rows = data->nb_rows;
    new_data->nb_columns = data->nb_columns;
    return new_data;
}
