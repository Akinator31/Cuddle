/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** create_dataframe
*/

#include <stddef.h>
#include <stdlib.h>
#include "dataframe.h"
#include "garbage_collector.h"
#include "utils.h"

static column_t *create_columns(size_t nb_columns, size_t nb_rows)
{
    column_t *column_list = my_malloc(sizeof(column_t) * nb_columns);

    for (size_t i = 0; i < nb_columns; i++) {
        column_list[i].type = UNDEFINED;
        column_list[i].name = NULL;
        column_list[i].content = NULL;
        column_list[i].content_strings = my_calloc(nb_rows, sizeof(char *));
    }
    return column_list;
}

dataframe_t *create_dataframe(size_t nb_rows, size_t nb_columns)
{
    dataframe_t *dataframe = my_malloc(sizeof(dataframe_t));

    dataframe->nb_rows = nb_rows;
    dataframe->nb_columns = nb_columns;
    dataframe->columns = create_columns(nb_columns, nb_rows);
    dataframe->delimiter = NULL;
    return dataframe;
}
