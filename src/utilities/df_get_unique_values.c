/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_get_unique_values
*/

#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

void *copy_data(void *data, column_type_t type, size_t index)
{
    return NULL;   
}

void **df_get_unique_values(
    dataframe_t *dataframe,
    const char *column)
{
    ssize_t column_index = 0;
    void **values_temp = NULL;
    void **values = malloc(sizeof(void *));

    if (!values || !dataframe || !column)
        return NULL;
    values = df_get_values(dataframe, column);
    column_index = find_column(dataframe, column);

    for (size_t i = 0; i < dataframe->nb_rows; i++) {
        values = realloc(values, sizeof(void *) * (i + 1));
        if (dataframe->columns[column_index].type == STRING) {
            values[i] = copy_data(&dataframe->columns[column_index], dataframe->columns[column_index].type, i);
        }
    }
}
