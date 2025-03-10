/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** create_dataframe
*/

#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

dataframe_t *create_dataframe(size_t nb_rows, size_t nb_columns)
{
    dataframe_t *new_dataframe = malloc(sizeof(dataframe_t));

    if (!new_dataframe)
        return NULL;
    new_dataframe->nb_columns = (size_t)nb_columns;
    new_dataframe->nb_rows = (size_t)nb_rows;
    return new_dataframe;
}
