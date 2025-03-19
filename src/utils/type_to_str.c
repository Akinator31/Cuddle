/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** type_to_str.c
*/

#include "dataframe.h"
#include "utils.h"
#include <stdio.h>

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

char *content_to_str(
    void *content,
    column_type_t type)
{
    char *string = NULL;

    if (type == INT)
        sprintf(string, "%d", *(int *)(content));
    if (type == UINT)
        sprintf(string, "%ud", *(uint *)(content));
    if (type == FLOAT)
        sprintf(string, "%f", *(double *)(content));
    if (type == BOOL && *(bool *)(content) == true)
        string = "true";
    if (type == BOOL && *(bool *)(content) == false)
        string = "false";
    if (type == STRING)
        return (char *)content;
    return string;
}
