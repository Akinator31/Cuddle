/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_get_value
*/

#include <string.h>
#include "dataframe.h"
#include "utils.h"

void *df_get_value(
    dataframe_t *dataframe,
    int int_row,
    const char *column)
{
    size_t row = (size_t)int_row;

    if (!dataframe || !column || row <= 0 || row > dataframe->nb_rows)
        return NULL;
    row--;
    for (size_t i = 0; i < dataframe->nb_columns; i++) {
        if (strcmp(dataframe->columns[i].name, column) == 0)
            return retrieve_data_from_column(&dataframe->columns[i], row);
    }
    return NULL;
}
