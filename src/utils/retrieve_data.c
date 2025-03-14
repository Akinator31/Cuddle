/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** retrieve_data.c
*/

#include "dataframe.h"
#include "utils.h"

void *retrieve_data_from_column(
    column_t *column,
    size_t row)
{
    if (column->type == STRING)
        return column->content_strings[row];
    if (column->type == INT)
        return &((int *)(column->content))[row];
    if (column->type == UINT)
        return &((unsigned int *)(column->content))[row];
    if (column->type == BOOL)
        return &((bool *)(column->content))[row];
    if (column->type == FLOAT)
        return &((double *)(column->content))[row];
    return NULL;
}
