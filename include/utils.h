/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H

    #include "dataframe.h"
    #include <stdint.h>

dataframe_t *create_dataframe(
    size_t nb_rows,
    size_t nb_columns);

column_t *copy_column_content_from_head(
    column_t *src,
    column_t *dest,
    size_t nb_rows);

column_t *copy_column_content_from_tail(
    column_t *src,
    column_t *dest,
    size_t nb_rows,
    size_t total_rows);

ssize_t find_column(
    const dataframe_t *data,
    const char *column_name);

dataframe_t *resolve_types(
    dataframe_t *data);

column_t *fill_column_types(
    column_t *column,
    column_type_t type,
    size_t nb_rows);

uint8_t content_size(column_type_t type);

// Free related
void df_free_safe(dataframe_t *data);
void free_column(
    column_t *column,
    size_t rows);
void free_all_columns(
    column_t *column_array,
    size_t rows,
    size_t cols);

void *retrieve_data_from_column(
    column_t *column,
    size_t row);
char *type_to_str(column_type_t type);

#endif
