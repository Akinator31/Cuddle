/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_get_value
*/

#include <string.h>
#include "dataframe.h"

static void *retrieve_data_from_column(
    column_t *column,
    int row)
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

void *df_get_value(
    dataframe_t *dataframe,
    int row,
    const char *column)
{
    if (!dataframe || !column || row <= 0 || row > dataframe->nb_rows)
        return NULL;
    row--;
    for (size_t i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->columns[i].name, column) == 0)
            return retrieve_data_from_column(&dataframe->columns[i], row);
    }
    return NULL;
}
