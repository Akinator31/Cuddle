/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_shape.c
*/

#include "dataframe.h"
#include "errors.h"
#include <sys/types.h>

dataframe_shape_t df_shape(
    dataframe_t *data)
{
    if (!data) {
        write_error(NO_DATAFRAME, NULL, -1);
        return (dataframe_shape_t){0, 0};
    }
    return (dataframe_shape_t){(int)data->nb_rows, (int)data->nb_columns};
}
