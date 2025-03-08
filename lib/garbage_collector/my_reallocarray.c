/*
** EPITECH PROJECT, 2025
** my_stdlib
** File description:
** my_reallocarray (non-standard)
*/

#include <stddef.h>
#include "garbage_collector.h"

void *my_reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return my_realloc(ptr, nmemb * size, size);
}
