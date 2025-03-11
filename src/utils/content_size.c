/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** content_size.c
*/

#include <stdint.h>
#include "dataframe.h"
#include "utils.h"

uint8_t content_size(column_type_t type)
{
    if (type == BOOL)
        return sizeof(bool);
    if (type == INT || type == UINT)
        return sizeof(int);
    if (type == FLOAT)
        return sizeof(double);
    if (type == STRING)
        return sizeof(char *);
    return 0;
}
