/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** dataframe structure
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H
    #include <stdbool.h>

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct column_s {
    column_type_t type;
    char **column_content;
} column_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    column_t **columns;
} dataframe_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

dataframe_t *df_read_csv(const char *filename, const char *separator);
dataframe_t *df_write_csv(dataframe_t *dataframe, const char *filename);

// BASICS OPERATIONS
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
dataframe_shape_t *df_shape(dataframe_t *dataframe);
void df_info(dataframe_t *dataframe);
void df_describe(dataframe_t *dataframe);

// FILTERING
dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value));

// SORTING
dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_function)(void *value1, void *value2));

// AGGREGATION
dataframe_t *df_groupby(dataframe_t *dataframe, const char *aggregate_by,
    const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values));

// TRANSFORMATION
dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value));
dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast);

// UTILITIES
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void df_free(dataframe_t *dataframe);

#endif /* DATAFRAME_H */
