/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** dataframe structure
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H
    #include <stdbool.h>
    #include "cuddle.h"

    #include <stddef.h>

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct PACKED column_s {
    column_type_t type;
    char *name;
    char **column_content;
} column_t;

typedef struct dataframe_s {
    size_t nb_rows;
    size_t nb_columns;
    column_t **columns;
} dataframe_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

// CORE FUNCTIONS
dataframe_t *df_read_csv(
    const char *filename,
    const char *separator)
__attribute__((nonnull(1)));
dataframe_t *df_write_csv(
    dataframe_t *dataframe,
    const char *filename)
__attribute__((nonnull(1, 2)));

// BASICS OPERATIONS
dataframe_t *df_head(
    dataframe_t *dataframe,
    int nb_rows)
__attribute__((nonnull(1)));
dataframe_t *df_tail(
    dataframe_t *dataframe,
    int nb_rows)
__attribute__((nonnull(1)));
dataframe_shape_t *df_shape(
    dataframe_t *dataframe)
__attribute__((nonnull(1)));
void df_info(
    dataframe_t *dataframe)
__attribute__((nonnull(1)));
void df_describe(
    dataframe_t *dataframe)
__attribute__((nonnull(1)));

// FILTERING
dataframe_t *df_filter(
    dataframe_t *dataframe,
    const char *column,
    bool (*filter_func)(void *value))
__attribute__((nonnull(1, 2, 3)));

// SORTING
dataframe_t *df_sort(dataframe_t *dataframe,
    const char *column,
    bool (*sort_function)(void *value1, void *value2))
__attribute__((nonnull(1, 2, 3)));

// AGGREGATION
dataframe_t *df_groupby(
    dataframe_t *dataframe,
    const char *aggregate_by,
    const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values))
__attribute__((nonnull(1, 2, 3, 4)));

// TRANSFORMATION
dataframe_t *df_apply(
    dataframe_t *dataframe,
    const char *column,
    void *(*apply_func)(void *value))
__attribute__((nonnull(1, 2, 3)));
dataframe_t *df_to_type(
    dataframe_t *dataframe,
    const char *column,
    column_type_t downcast)
__attribute__((nonnull(1, 2)));

// UTILITIES
void *df_get_value(
    dataframe_t *dataframe,
    int row,
    const char *column)
__attribute__((nonnull(1, 3)));
void **df_get_values(
    dataframe_t *dataframe,
    const char *column)
__attribute__((nonnull(1, 2)));
void **df_get_unique_values(
    dataframe_t *dataframe,
    const char *column)
__attribute__((nonnull(1, 2)));
void df_free(
    dataframe_t *dataframe)
__attribute__((nonnull(1)));

#endif /* DATAFRAME_H */
