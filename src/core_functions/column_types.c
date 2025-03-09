/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** column_types
*/

#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include "dataframe.h"
#include "lib.h"

static bool is_bool(char *string)
{
    if (strcasecmp(string, "true") == 0 ||
        strcasecmp(string, "false") == 0)
        return true;
    return false;
}

static bool is_float(char *string)
{
    size_t dot_count = 0;

    if (string[0] == '-')
        string++;
#ifndef CSV_DOTED_FLOATS
    if (!isdigit(string[0]))
        return false;
    string++;
#endif
    for (size_t i = 0; isdigit(string[i]) || string[i] == '.'; i++)
        if (string[i] == '.')
            dot_count++;
    if (dot_count != 1)
        return false;
    return true;
}

static bool is_int(char *string)
{
    if (string[0] == '-')
        string++;
    for (size_t i = 0; string[i]; i++)
        if (!isdigit(string[i]))
                return false;
    return true;
}

static column_type_t identify_type(char *string)
{
    char *clean_string = string;

#ifdef CSV_SPACED_VALUE
    clean_string = clean_str(string);
#endif
    if (is_bool(clean_string))
        return BOOL;
    if (is_float(clean_string))
        return FLOAT;
    if (is_int(clean_string))
        return INT;
    return STRING;
}

static column_type_t identify_column_type(
    column_t *column,
    size_t rows)
{
    column_type_t estimated_type = UNDEFINED;
    column_type_t current_type = UNDEFINED;

    estimated_type = identify_type(column->content_strings[0]);
    for (size_t i = 1; i < rows; i++) {
        current_type = identify_type(column->content_strings[i]);
        if (current_type != estimated_type) {
            estimated_type = STRING;
            break;
        }
    }
    column->type = estimated_type;
    return estimated_type;
}

dataframe_t *resolve_types(dataframe_t *data)
{
    for (size_t i = 0; i < data->nb_columns; i++) {
        identify_column_type(data->columns[i], data->nb_rows);
        // change all types
    }
    return data;
}
