/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** apply_sorting_mask
*/

#include <sys/types.h>
#include "dataframe.h"
#include "utils.h"

static void swap_int_uint_column(
    dataframe_t *dataframe,
    size_t index,
    size_t min_index,
    size_t column_index)
{
    int temp = 0;

    temp = ((int *)(dataframe->columns[column_index].content))[index];
    ((int *)(dataframe->columns[column_index].content))[index] =
        ((int *)(dataframe->columns[column_index].content))[min_index];
    ((int *)(dataframe->columns[column_index].content))[min_index] = temp;
}

static void swap_float_column(
    dataframe_t *dataframe,
    size_t index,
    size_t min_index,
    size_t column_index)
{
    double temp_double = 0.0;

    temp_double =
        ((double *)(dataframe->columns[column_index].content))[index];
    ((double *)(dataframe->columns[column_index].content))[index] =
        ((double *)(dataframe->columns[column_index].content))[min_index];
    ((double *)(dataframe->columns[column_index].content))[min_index] =
        temp_double;
}

void apply_sorting_mask_for_all_columns(
    size_t index,
    size_t min_index,
    dataframe_t *dataframe)
{
    char *tempo = NULL;

    for (size_t i = 0; i < dataframe->nb_columns; i++) {
        tempo = dataframe->columns[i].content_strings[index];
        dataframe->columns[i].content_strings[index] =
            dataframe->columns[i].content_strings[min_index];
        dataframe->columns[i].content_strings[min_index] = tempo;
        if (dataframe->columns[i].type == INT ||
            dataframe->columns[i].type == UINT)
            swap_int_uint_column(dataframe, index, min_index, i);
        if (dataframe->columns[i].type == FLOAT)
            swap_float_column(dataframe, index, min_index, i);
    }
}
