/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_dump
*/

#include <stdio.h>
#include "dataframe.h"

void df_dump(dataframe_t *dataframe)
{
    for (size_t i = 0; i < dataframe->nb_columns; i++) {
        printf("| %-10s ", dataframe->columns[i]->name);
    }
    printf("|\n");
    for (size_t i = 0; i < dataframe->nb_columns; i++) {
        printf("|------------");
    }
    printf("|\n");
    for (size_t e = 0; e < dataframe->nb_rows; e++) {
        for (size_t i = 0; i < dataframe->nb_columns; i++) {
            printf("| %-10s ", dataframe->columns[i]->column_content[e]);
        }
        printf("|\n");
    }
}
