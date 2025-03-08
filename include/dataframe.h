/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** dataframe structure
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H

    #include <stddef.h>

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
    char *name;
    char **column_content;
} column_t;

typedef struct dataframe_s {
    size_t nb_rows;
    size_t nb_columns;
    column_t **columns;
} dataframe_t;

dataframe_t *df_read_csv(const char *filename, const char *separator);

#endif /* DATAFRAME_H */
