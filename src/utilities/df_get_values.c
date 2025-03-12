/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_get_values
*/

#include <stdlib.h>
#include <string.h>
#include "dataframe.h"

static void **retrieve_column(
    column_t *column,
    size_t nb_rows)
{
    void **values = malloc(sizeof(void *) * (nb_rows + 1));

    if (!values)
        return NULL;
    for (size_t i = 0; i < nb_rows; i++) {
        if (column->type == STRING)
            values[i] = column->content_strings[i];
        if (column->type == INT)
            values[i] = &((int *)(column->content))[i];
        if (column->type == UINT)
            values[i] = &((unsigned int *)(column->content))[i];
        if (column->type == BOOL)
            values[i] = &((bool *)(column->content))[i];
        if (column->type == FLOAT)
            values[i] = &((double *)(column->content))[i];
    }
    values[nb_rows] = NULL;
    return values;
}

void **df_get_values(
    dataframe_t *dataframe,
    const char *column)
{
    if (!dataframe || !column)
        return NULL;
    for (size_t i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->columns[i].name, column) == 0)
            return retrieve_column(&dataframe->columns[i], dataframe->nb_rows);
    }
    return NULL;
}
