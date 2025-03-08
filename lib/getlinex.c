/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** getlinex
*/

#include <stdio.h>
#include <string.h>
#include <lib.h>

ssize_t getlinex(
    char **restrict lineptr,
    size_t *restrict n,
    FILE *restrict stream)
{
    ssize_t result = getline(lineptr, n, stream);

    if (result == -1)
        return -1;
    if (lineptr)
        (*lineptr)[strcspn(*lineptr, "\n")] = '\0';
    return result;
}
