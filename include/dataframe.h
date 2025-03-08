/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** dataframe structure
*/

#ifndef DATAFRAME_H
    #define DATAFRAME_H

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    column_type_t *types;
} dataframe_t;

dataframe_t *df_read_csv(const char *filename, const char *separator);

#endif /* DATAFRAME_H */
