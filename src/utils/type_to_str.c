/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** type_to_str.c
*/

#include "dataframe.h"
#include "utils.h"

char *type_to_str(column_type_t type)
{
    if (type == BOOL)
        return "bool";
    if (type == INT)
        return "int";
    if (type == UINT)
        return "unsigned int";
    if (type == FLOAT)
        return "float";
    if (type == STRING)
        return "string";
    return NULL;
}
