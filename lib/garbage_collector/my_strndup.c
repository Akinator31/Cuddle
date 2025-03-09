/*
** EPITECH PROJECT, 2025
** my_string
** File description:
** my_strndup (non-standard)
*/

#include <string.h>
#include "garbage_collector.h"

char *my_strndup(const char *str, size_t bytes)
{
    size_t len = strlen(str);
    char *duplicata = NULL;

    if (bytes > len)
        bytes = len;
    duplicata = my_calloc(sizeof(char), bytes + 1);
    memcpy(duplicata, str, bytes);
    return duplicata;
}
