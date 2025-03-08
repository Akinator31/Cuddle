/*
** EPITECH PROJECT, 2025
** my_string
** File description:
** my_strdup (non-standard)
*/

#include <string.h>
#include "garbage_collector.h"

char *my_strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char *duplicata = my_malloc(len);

    memcpy(duplicata, str, len);
    return duplicata;
}
