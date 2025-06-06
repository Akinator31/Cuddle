/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#include <stdbool.h>
#include <stdio.h>
#include <lib.h>
#include <stdlib.h>
#include <string.h>

void print_str_array(char **array)
{
    if (!array)
        return;
    for (size_t i = 0; array[i]; i++)
        puts(array[i]);
}

size_t str_array_len(char **array)
{
    size_t count = 0;

    while (array[count] != NULL)
        count++;
    return count;
}

void *free_str_array(char **array)
{
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return NULL;
}

bool str_in_array(char *str, char **array)
{
    for (size_t i = 0; array[i]; i++)
        if (!strcmp(str, array[i]))
            return true;
    return false;
}
