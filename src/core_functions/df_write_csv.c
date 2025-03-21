/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_write_csv.c
*/

#include "dataframe.h"
#include "errors.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

static void df_write_header(dataframe_t *data, FILE *fptr)
{
    for (size_t i = 0; i < data->nb_columns - 1; i++)
        fprintf(fptr, "%s%s", data->columns[i].name, data->delimiter);
    fprintf(fptr, "%s\n", data->columns[data->nb_columns - 1].name);
}

static void df_write_content(dataframe_t *data, size_t row, FILE *fptr)
{
    for (size_t i = 0; i < data->nb_columns - 1; i++)
        fprintf(fptr, "%s%s",
            data->columns[i].content_strings[row], data->delimiter);
    fprintf(fptr, "%s\n",
        data->columns[data->nb_columns - 1].content_strings[row]);
}

int df_write_csv(dataframe_t *data, const char *filename)
{
    FILE *fptr = NULL;

    if (!data) {
        write_error(NO_DATAFRAME, NULL, -1);
        return 84;
    }
    fptr = fopen(filename, "w");
    if (!fptr) {
        perror(strerror(errno));
        return 84;
    }
    df_write_header(data, fptr);
    for (size_t i = 0; i < data->nb_rows; i++)
        df_write_content(data, i, fptr);
    fclose(fptr);
    return 0;
}
