/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_groupby.c
*/

#include "dataframe.h"
#include "utils.h"

dataframe_t *df_groupby(
    dataframe_t *data,
    const char *aggregate_by,
    const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values))
{
    ssize_t col_nb = 0;

    if (!data || !aggregate_by || !to_aggregate || !agg_func)
        return NULL;
    col_nb = find_column(data, aggregate_by);
    if (col_nb == -1)
        return NULL;
    for (size_t i = 0; i < data->nb_rows; i++) {
        col_nb = find_column(data, to_aggregate[i]);
        if (col_nb == -1)
            return NULL;
    }
    return data;
}
