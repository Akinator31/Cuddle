/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_free
*/

#include <stdlib.h>
#include "dataframe.h"

static void free_column(column_t *column, size_t rows)
{
    if (!column)
        return;
    for (size_t i = 0; i < rows; i++) {
        if (column->column_content[i])
            free(column->column_content[i]);
    }
    if (column->name)
        free(column->name);
}

void df_free(dataframe_t *dataframe)
{
    if (!dataframe)
        return;
    for (size_t i = 0; i < dataframe->nb_columns; i++)
        free_column(dataframe->columns[i], dataframe->nb_rows);
}
