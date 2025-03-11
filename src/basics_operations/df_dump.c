/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_dump
*/

#include <stdio.h>
#include <sys/types.h>
#include "dataframe.h"

static void print_type(column_type_t type)
{
    if (type == INT)
        printf("| %-10s ", "Int");
    if (type == UINT)
        printf("| %-10s ", "Uint");
    if (type == FLOAT)
        printf("| %-10s ", "Float");
    if (type == BOOL)
        printf("| %-10s ", "Bool");
    if (type == STRING)
        printf("| %-10s ", "String");
}

static void print_content(
    column_t *column,
    size_t row,
    column_type_t type)
{
    if (type == INT)
        printf("| %-10d ", ((int *)(column->content))[row]);
    if (type == UINT)
        printf("| %-10u ", ((uint *)(column->content))[row]);
    if (type == BOOL) {
        if (((int *)(column->content))[row] == 0)
            printf("| %-10s ", "false");
        else
            printf("| %-10s ", "true");
    }
    if (type == FLOAT)
        printf("| %-10f ", ((double *)(column->content))[row]);
    if (type == STRING)
        printf("| %-10s ", column->content_strings[row]);
}

void df_dump(dataframe_t *dataframe)
{
    if (!dataframe)
        return;
    for (size_t i = 0; i < dataframe->nb_columns; i++)
        printf("| %-10s ", dataframe->columns[i].name);
    printf("|\n");
    for (size_t i = 0; i < dataframe->nb_columns; i++)
        print_type(dataframe->columns[i].type);
    printf("|\n");
    for (size_t i = 0; i < dataframe->nb_columns; i++)
        printf("|------------");
    printf("|\n");
    for (size_t e = 0; e < dataframe->nb_rows; e++) {
        for (size_t i = 0; i < dataframe->nb_columns; i++)
            print_content(&dataframe->columns[i], e,
                dataframe->columns[i].type);
        printf("|\n");
    }
}
