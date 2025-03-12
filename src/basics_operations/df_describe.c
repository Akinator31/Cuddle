/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_describe.c
*/

#include <stddef.h>
#include <stdio.h>
#include "dataframe.h"
#include "utils.h"

static void get_column_data(column_t *column, double data[4], size_t nb_rows)
{
    for (size_t i = 0; i < nb_rows; i++) {
        printf("%f\n", data[0]);
    }
    data[0] /= (double)nb_rows;
    return;
}

static void describe_column(column_t *column, size_t nb_rows)
{
    double data[4] = {0};

    get_column_data(column, data, nb_rows);
    printf(
        "Column: %s\n"
        "Count: %lu\n"
        "Mean: %f\n",
        column->name, nb_rows, data[0]);
    return;
}

void df_describe(dataframe_t *data)
{
    column_type_t type = UNDEFINED;

    if (!data)
        return;
    for (size_t i = 0; i < data->nb_columns; i++) {
        type = data->columns[i].type;
        if (type == INT || type == UINT || type == FLOAT)
            describe_column(&data->columns[i], data->nb_rows);
    }
}
