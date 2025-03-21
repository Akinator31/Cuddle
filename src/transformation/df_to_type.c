/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_to_type.c
*/

#include "dataframe.h"
#include "utils.h"
#include "errors.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool apply_bool_downcast(
    char *content,
    column_type_t type)
{
    if (type == INT || type == UINT)
        return (atoi(content) != 0);
    if (type == FLOAT)
        return (atof(content) != 0.00);
    if (type == BOOL)
        return (!strcmp(content, "true"));
    return false;
}

static column_t *apply_downcast(
    column_t *column,
    column_type_t downcast,
    size_t nb_rows)
{
    for (size_t i = 0; i < nb_rows; i++) {
        if (downcast == INT || downcast == UINT)
            ((int *)(column->content))[i] = atoi(column->content_strings[i]);
        if (downcast == FLOAT)
            ((double *)(column->content))[i] =
                atof(column->content_strings[i]);
        if (downcast == BOOL && column->type == STRING)
            ((bool *)(column->content))[i] = true;
        if (downcast == BOOL && column->type != STRING)
            ((bool *)(column->content))[i] = apply_bool_downcast(
                column->content_strings[i], column->type);
        modify_string(column, i, downcast);
    }
    return column;
}

static column_t *prepare_downcast(
    column_t *column,
    column_type_t downcast,
    size_t nb_rows)
{
    if (downcast != STRING) {
        if (column->content)
            free(column->content);
        column->content = malloc(content_size(downcast) * nb_rows);
    }
    return column;
}

dataframe_t *df_to_type(
    dataframe_t *data,
    const char *name,
    column_type_t downcast)
{
    ssize_t col = 0;
    dataframe_t *new = NULL;
    column_t *column = NULL;

    if (!data || downcast >= UNDEFINED)
        return NULL;
    col = find_column(data, name);
    if (col == -1)
        return write_error(COLUMN_NOT_FOUND, name, -1);
    column = &data->columns[(size_t)col];
    if (!check_downcast(column, downcast, data->nb_rows))
        return write_error(BAD_DOWNCAST, column->name, -1);
    new = create_dataframe(data->nb_rows, data->nb_columns, data->delimiter);
    copy_columns(data, new);
    column = &new->columns[(size_t)col];
    prepare_downcast(column, downcast, data->nb_rows);
    apply_downcast(column, downcast, data->nb_rows);
    column->type = downcast;
    return new;
}
