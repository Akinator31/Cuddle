/*
** EPITECH PROJECT, 2025
** my_malloc
** File description:
** Free a pseudo-allocated memory block
** Only works with my_malloc allocated blocks
** Currently returning maximal values on error, probably shouldn't
*/

#include <stdlib.h>
#include "garbage_collector.h"

void free_garbage(void)
{
    collect_garbage(NULL, NULL, FREE_MODE);
}
