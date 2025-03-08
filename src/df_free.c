/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_free
*/

#include <stdlib.h>
#include "dataframe.h"

static void free_column(column_t *column)
{
    for (int i = 0; column->column_content[i]; i++)
        free(column->column_content[i]);
}

void df_free(dataframe_t *dataframe)
{
    if (!dataframe)
        return;
    for (int i = 0; i < dataframe->nb_columns; i++)
        free_column(dataframe->columns[i]);
}
