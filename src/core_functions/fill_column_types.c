/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** fill_column_types.c
*/

#include "dataframe.h"
#include "garbage_collector.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static column_t *fill_bool(
    column_t *column,
    size_t nb_rows)
{
    for (size_t i = 0; i < nb_rows; i++) {
        column->content[i] = my_malloc(sizeof(column_type_t));
        if (tolower(column->content_strings[i][0]) == 'f')
            column->content[i]->boolean = false;
        else
            column->content[i]->boolean = true;
    }
    return column;
}

static column_t *fill_float(
    column_t *column,
    size_t nb_rows)
{
    for (size_t i = 0; i < nb_rows; i++) {
        column->content[i] = my_malloc(sizeof(column_type_t));
        column->content[i]->floating_point = atof(column->content_strings[i]);
    }
    return column;
}

static column_t *fill_int(
    column_t *column,
    size_t nb_rows,
    bool *negative)
{
    for (size_t i = 0; i < nb_rows; i++) {
        column->content[i] = my_malloc(sizeof(column_type_t));
        column->content[i]->integer = atoi(column->content_strings[i]);
        if (column->content[i]->integer < 0)
            *negative = true;
    }
    return column;
}

column_t *fill_column_types(
    column_t *column,
    column_type_t *type,
    size_t nb_rows)
{
    bool negative = false;

    column->content = my_malloc(sizeof(column_type_t *) * nb_rows);
    if (*type == BOOL)
        fill_bool(column, nb_rows);
    if (*type == INT)
        fill_int(column, nb_rows, &negative);
    if (*type == FLOAT)
        fill_float(column, nb_rows);
    if (!negative)
        *type = UINT;
    return column;
}
