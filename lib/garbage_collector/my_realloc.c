/*
** EPITECH PROJECT, 2024
** my_stdlib
** File description:
** reallocate the desired memory size
*/

#include <string.h>
#include <stddef.h>
#include "garbage_collector.h"

void *my_realloc(void *ptr, size_t size, size_t old_size)
{
    void *new_ptr = my_malloc(size);

    memcpy(new_ptr, ptr, old_size);
    collect_garbage(NULL, ptr, MODIF_MODE);
    return new_ptr;
}
