/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#include <stdio.h>
#include <lib.h>

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
