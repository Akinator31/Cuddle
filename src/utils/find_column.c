/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** find_column.c
*/

#include <string.h>
#include "dataframe.h"
#include "utils.h"

ssize_t find_column(
    const dataframe_t *data,
    const char *column_name)
{
    if (!data || !column_name)
        return 0;
    for (ssize_t i = 0; i < (ssize_t)data->nb_columns; i++)
        if (!strcmp(column_name, data->columns[i].name))
            return i;
    return -1;
}
