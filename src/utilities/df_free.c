/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_free
*/

#include <stdio.h>
#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

void free_column(
    column_t *column,
    size_t rows)
{
    if (!column)
        return;
    for (size_t i = 0; i < rows; i++) {
        if (column->content_strings[i])
            free(column->content_strings[i]);
    }
    free(column->content_strings);
    free(column->content);
    if (column->name)
        free(column->name);
    if (column->content)
        free(column->content);
    if (!column->content_strings)
        return;
    for (size_t i = 0; i < rows; i++)
        if (column->content_strings[i])
            free(column->content_strings[i]);
    free(column->content_strings);
}

void free_all_columns(
    column_t *column_array,
    size_t rows,
    size_t cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            free(column_array[j].content_strings[i]);
    for (size_t i = 0; i < cols; i++) {
        free(column_array[i].name);
        free(column_array[i].content);
        free(column_array[i].content_strings);
    }
}

void df_free_safe(dataframe_t *data)
{
    if (!data)
        return;
    for (size_t i = 0; i < data->nb_columns; i++)
        free_column(&data->columns[i], data->nb_rows);
    free(data->columns);
    free(data);
}

void df_free(dataframe_t *data)
{
    if (!data)
        return;
    free_all_columns(data->columns, data->nb_rows, data->nb_columns);
    free(data->columns);
    free(data);
}
