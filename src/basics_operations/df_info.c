/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_info.c
*/

#include <stdio.h>
#include "errors.h"
#include "utils.h"
#include "dataframe.h"

void df_info(dataframe_t *data)
{
    if (!data) {
        write_error(NO_DATAFRAME, NULL, -1);
        return;
    }
    printf("%lu columns:\n", data->nb_columns);
    for (size_t i = 0; i < data->nb_columns - 1; i++)
        printf("- %s: %s\n",
            data->columns[i].name, type_to_str(data->columns[i].type));
    printf("- %s: %s", data->columns[data->nb_columns - 1].name,
        type_to_str(data->columns[data->nb_columns - 1].type));
}
