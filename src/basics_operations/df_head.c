/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_head
*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dataframe.h"
#include "utils.h"

static void dump_column_content(
    column_t *column_src,
    column_t *column_dest,
    size_t nb_rows)
{
    if (!column_dest || !column_dest->content_strings)
        return;
    if (!nb_rows)
        return;
    for (size_t i = 0; i < (size_t)nb_rows; i++)
        column_dest->content_strings[i] =
            strdup(column_src->content_strings[i]);
}

static column_t **dump_columns(
    dataframe_t *df_src,
    dataframe_t *df_dest)
{
    size_t i = 0;
    column_t **data = malloc(sizeof(column_t *) * df_src->nb_columns);

    while (i < df_src->nb_columns) {
        data[i] = malloc(sizeof(column_t));
        if (!data[i])
            return NULL;
        data[i]->name = strdup(df_src->columns[i]->name);
        data[i]->type = df_src->columns[i]->type;
        data[i]->content_strings = malloc(sizeof(char *) * df_src->nb_rows);
        dump_column_content(df_src->columns[i], data[i], df_dest->nb_rows);
        i++;
    }
    return data;
}

static dataframe_t *dump_dataframe(
    dataframe_t *df_src,
    size_t nb_rows)
{
    size_t dataframe_size = nb_rows;
    dataframe_t *new_dataframe = NULL;

    if (!df_src)
        return NULL;
    if (nb_rows > df_src->nb_rows)
        dataframe_size = df_src->nb_rows;
    new_dataframe = create_dataframe(dataframe_size, df_src->nb_columns);
    new_dataframe->columns = dump_columns(df_src, new_dataframe);
    return new_dataframe;
}

dataframe_t *df_head(
    dataframe_t *dataframe,
    int nb_rows)
{
    dataframe_t *new_dataframe = NULL;

    if (!dataframe || nb_rows < 0)
        return NULL;
    new_dataframe = dump_dataframe(dataframe, (size_t)nb_rows);
    return new_dataframe;
}
