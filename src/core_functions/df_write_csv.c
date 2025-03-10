/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_write_csv.c
*/

#include "dataframe.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

static void df_write_header(dataframe_t *data, FILE *fptr)
{
    for (size_t i = 0; i < data->nb_columns - 1; i++)
        fprintf(fptr, "%s,", data->columns[i]->name);
    fprintf(fptr, "%s\n", data->columns[data->nb_columns - 1]->name);
}

static void df_write_content(dataframe_t *data, size_t row, FILE *fptr)
{
    for (size_t i = 0; i < data->nb_columns - 1; i++)
        fprintf(fptr, "%s,", data->columns[i]->content_strings[row]);
    fprintf(fptr, "%s\n",
        data->columns[data->nb_columns - 1]->content_strings[row]);
}

int df_write_csv(dataframe_t *data, const char *filename)
{
    FILE *fptr = NULL;

    fptr = fopen(filename, "w");
    if (!fptr) {
        perror(strerror(errno));
        return 84;
    }
    df_write_header(data, fptr);
    for (size_t i = 0; i < data->nb_rows; i++)
        df_write_content(data, i, fptr);
    return 0;
}
