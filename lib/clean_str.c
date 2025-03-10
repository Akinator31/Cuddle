/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** clean_str
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

char *clean_str(char *str)
{
    size_t start = 0;
    size_t end = strlen(str) - 1;
    size_t i = 0;

    while (str[start] != '\0' && isspace(str[start]))
        start++;
    if (str[start] == '\0') {
        str[0] = '\0';
        return str;
    }
    while (end >= start && isspace(str[end]))
        end--;
    while (start <= end)
        str[i++] = str[start++];
    str[i] = '\0';
    return str;
}
