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
