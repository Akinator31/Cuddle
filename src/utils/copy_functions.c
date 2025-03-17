/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** copy_columns.c
*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

column_t *copy_column_content_from_head(
    column_t *src,
    column_t *dest,
    size_t nb_rows)
{
    size_t total_content_size = content_size(src->type) * nb_rows;

    dest->type = src->type;
    dest->name = strdup(src->name);
    for (size_t i = 0; i < nb_rows; i++)
        dest->content_strings[i] = strdup(src->content_strings[i]);
    if (src->type == STRING)
        return dest;
    dest->content = malloc(total_content_size);
    memcpy(dest->content, src->content, total_content_size);
    return dest;
}

column_t *copy_column_content_from_tail(
    column_t *src,
    column_t *dest,
    size_t nb_rows,
    size_t total_rows)
{
    size_t total_content_size = content_size(src->type) * nb_rows;

    dest->type = src->type;
    dest->name = strdup(src->name);
    for (size_t i = 0; i < nb_rows; i++)
        dest->content_strings[i] =
        strdup(src->content_strings[total_rows - nb_rows + i]);
    if (src->type == STRING)
        return dest;
    dest->content = malloc(total_content_size);
    memcpy(dest->content, (char *)src->content + content_size(src->type)
        * (total_rows - nb_rows), total_content_size);
    return dest;
}

dataframe_t *copy_row(
    dataframe_t *src,
    dataframe_t *dest,
    size_t row_src,
    size_t row_dest)
{
    for (size_t i = 0; i < src->nb_columns; i++) {
        dest->columns[i].content_strings[row_dest] =
            strdup(src->columns[i].content_strings[row_src]);
        if (src->columns[i].type == INT || src->columns[i].type == UINT)
            ((int *)(dest->columns[i].content))[row_dest] =
                ((int *)(src->columns[i].content))[row_src];
        if (src->columns[i].type == FLOAT)
            ((double *)(dest->columns[i].content))[row_dest] =
                ((double *)(src->columns[i].content))[row_src];
        if (src->columns[i].type == BOOL)
            ((bool *)(dest->columns[i].content))[row_dest] =
                ((bool *)(src->columns[i].content))[row_src];
    }
    return dest;
}
