/*
** EPITECH PROJECT, 2024
** my_stdlib
** File description:
** return a memory block with all bytes set to 0
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "garbage_collector.h"

void *my_calloc(size_t nitems, size_t size)
{
    void *memory = my_malloc(nitems * size);

    memset(memory, 0, nitems * size);
    return memory;
}
