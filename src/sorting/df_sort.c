/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_sort
*/

#include <string.h>
#include <stdbool.h>
#include "dataframe.h"
#include "errors.h"
#include "utils.h"

static dataframe_t *apply_sorting(
    dataframe_t *new_dataframe,
    column_t *column_to_sort,
    bool (*sort_function)(void *value1, void *value2))
{
    size_t j = 0;

    for (size_t i = 1; i < new_dataframe->nb_rows; i++) {
        j = i;
        while (j > 0 && sort_function(
            retrieve_data_from_column(column_to_sort, j - 1),
            retrieve_data_from_column(column_to_sort, j))) {
            apply_sorting_mask_for_all_columns(j, j - 1, new_dataframe);
            j--;
        }
    }
    return new_dataframe;
}

dataframe_t *df_sort(
    dataframe_t *dataframe,
    const char *column,
    bool (*sort_function)(void *value1, void *value2))
{
    ssize_t column_index = 0;
    column_t *column_to_sort = NULL;
    dataframe_t *new_dataframe = NULL;

    if (!dataframe || !column || !sort_function || !strlen(column))
        return write_error(NO_DATAFRAME, NULL, -1);
    column_index = find_column(dataframe, column);
    if (column_index == -1)
        return write_error(COLUMN_NOT_FOUND, column, -1);
    new_dataframe = df_head(dataframe, (int)dataframe->nb_rows);
    column_to_sort = &new_dataframe->columns[column_index];
    if (!column_to_sort)
        return new_dataframe;
    return apply_sorting(new_dataframe, column_to_sort, sort_function);
}
