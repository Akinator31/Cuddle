/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** type_to_str.c
*/

#include "dataframe.h"
#include "utils.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static size_t find_content_size(
    void *content,
    column_type_t type)
{
    size_t size = 0;

    if (type == INT)
        size = (size_t)snprintf(NULL, 0, "%d", *(int *)(content), INT_MAX);
    if (type == UINT)
        size = (size_t)snprintf(NULL, 0, "%ud", *(uint *)(content), INT_MAX);
    if (type == FLOAT)
        size = (size_t)snprintf(NULL, 0, "%f", *(double *)(content), INT_MAX);
    return size;
}

char *content_to_str(
    void *content,
    column_type_t type)
{
    size_t buf_size = 0;
    char *string = NULL;

    if (type == BOOL && *(bool *)(content) == true)
        return strdup("true");
    if (type == BOOL && *(bool *)(content) == false)
        return strdup("false");
    if (type == STRING)
        return strdup((char *)content);
    buf_size = find_content_size(content, type);
    string = calloc(sizeof(char), (buf_size + 1));
    if (type == INT)
        sprintf(string, "%d", *(int *)(content));
    if (type == UINT)
        sprintf(string, "%ud", *(uint *)(content));
    if (type == FLOAT)
        sprintf(string, "%.2f", *(double *)(content));
    return string;
}
