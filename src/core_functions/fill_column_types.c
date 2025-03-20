/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** fill_column_types.c
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

static column_t *fill_bool(
    column_t *column,
    size_t nb_rows)
{
    column->content = malloc(sizeof(bool) * nb_rows);
    for (size_t i = 0; i < nb_rows; i++)
        ((bool *)(column->content))[i] =
            tolower(column->content_strings[i][0]) == 't';
    return column;
}

static column_t *fill_float(
    column_t *column,
    size_t nb_rows)
{
    column->content = malloc(sizeof(double) * nb_rows);
    for (size_t i = 0; i < nb_rows; i++) {
        ((double *)(column->content))[i] = atof(column->content_strings[i]);
    }
    return column;
}

static column_t *fill_int(
    column_t *column,
    size_t nb_rows)
{
    bool negative = false;

    column->content = malloc(sizeof(int) * nb_rows);
    for (size_t i = 0; i < nb_rows; i++) {
        ((int *)(column->content))[i] = atoi(column->content_strings[i]);
        if (((int *)(column->content))[i] >> 7)
            negative = true;
    }
    if (!negative)
        column->type = UINT;
    return column;
}

column_t *fill_column_types(
    column_t *column,
    column_type_t type,
    size_t nb_rows)
{
    if (type == BOOL)
        return fill_bool(column, nb_rows);
    if (type == INT)
        return fill_int(column, nb_rows);
    if (type == FLOAT)
        return fill_float(column, nb_rows);
    return column;
}
