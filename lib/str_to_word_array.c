/*
** EPITECH PROJECT, 2025
** asm
** File description:
** str to word array
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

static bool is_delim(
    char c,
    const char *delim)
{
    if (c == '\0')
        return true;
    for (int i = 0; delim[i] != '\0'; i++)
        if (c == delim[i])
            return true;
    return false;
}

static size_t count_delim(const char *str, const char *delim)
{
    size_t count = 0;

    for (size_t i = 0; str[i]; i++)
        if (is_delim(str[i], delim))
            count++;
    return count;
}

static int find_non_delim(
    const char *str,
    int i,
    const char *delim)
{
    while (str[i] != '\0') {
        if (!is_delim(str[i], delim))
            break;
        i++;
    }
    return i;
}

static int find_delim(
    const char *str,
    int i,
    const char *delim)
{
    while (str[i] != '\0') {
        if (is_delim(str[i], delim))
            break;
        i++;
    }
    return i;
}

char **str_to_word_array(
    const char *str,
    const char *delim)
{
    int index = 0;
    int word_size = 0;
    char **array =
        malloc(sizeof(char *) * (count_delim(str, delim) + 2));

    str = &str[find_non_delim(str, 0, delim)];
    for (int i = 0; str[i] != '\0'; index++) {
        word_size = (find_delim(str, i, delim) - i + 1);
        array[index] = calloc((size_t)word_size, sizeof(char));
        if (is_delim(str[i], delim))
            i = find_non_delim(str, i, delim);
        for (int j = 0; !is_delim(str[i], delim) == true; j++) {
            array[index][j] = str[i];
            i++;
        }
        i = find_non_delim(str, i, delim);
    }
    array[index] = NULL;
    return array;
}
