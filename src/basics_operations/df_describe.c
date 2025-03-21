/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_describe.c
*/

#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <float.h>
#include "dataframe.h"
#include "errors.h"

static void is_min_or_max(
    double number,
    double min_max[2])
{
    if (number < min_max[0])
        min_max[0] = number;
    if (number > min_max[1])
        min_max[1] = number;
}

static double get_column_mean(
    column_t *column,
    size_t nb_rows,
    double min_max[2])
{
    double tmp = 0;
    double mean = 0;

    for (size_t i = 0; i < nb_rows; i++) {
        if (column->type == INT)
            tmp = ((int *)(column->content))[i];
        if (column->type == UINT)
            tmp = ((uint *)(column->content))[i];
        if (column->type == FLOAT)
            tmp = ((double *)(column->content))[i];
        is_min_or_max(tmp, min_max);
        mean += tmp;
    }
    return mean / (double)nb_rows;
}

static double get_column_std(
    column_t *column,
    double mean,
    size_t nb_rows)
{
    double std = 0;

    for (size_t i = 0; i < nb_rows; i++) {
        if (column->type == INT)
            std += pow(((int *)(column->content))[i] - mean, 2);
        if (column->type == UINT)
            std += pow(((uint *)(column->content))[i] - mean, 2);
        if (column->type == FLOAT)
            std += pow(((double *)(column->content))[i] - mean, 2);
    }
    return sqrt(std / (double)nb_rows);
}

static void describe_column(
    column_t *column,
    size_t nb_rows)
{
    double min_and_max[2] = {DBL_MAX, DBL_MIN};
    double mean = get_column_mean(column, nb_rows, min_and_max);
    double std = get_column_std(column, mean, nb_rows);

    printf(
        "Column: %s\n"
        "Count: %lu\n"
        "Mean: %.2f\n"
        "Std: %.2f\n"
        "Min: %.2f\n"
        "Max: %.2f\n",
        column->name, nb_rows, mean, std, min_and_max[0], min_and_max[1]);
    return;
}

void df_describe(dataframe_t *data)
{
    column_type_t type = UNDEFINED;

    if (!data) {
        write_error(NO_DATAFRAME, NULL, -1);
        return;
    }
    for (size_t i = 0; i < data->nb_columns; i++) {
        type = data->columns[i].type;
        if (type == INT || type == UINT || type == FLOAT)
            describe_column(&data->columns[i], data->nb_rows);
    }
}
