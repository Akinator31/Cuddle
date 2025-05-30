/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** getlinex
*/

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <lib.h>

ssize_t getlinex(
    char **restrict lineptr,
    FILE *restrict stream)
{
    size_t n = 0;
    ssize_t result = getline(lineptr, &n, stream);

    if (result == -1)
        return -1;
    if (lineptr)
        (*lineptr)[strcspn(*lineptr, "\n\r")] = '\0';
    return result;
}
