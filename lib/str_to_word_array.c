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
#include "garbage_collector.h"
#include "lib.h"

static bool is_delim(
    char c,
    const char *delim)
{
    if (c == '\0')
        return true;
    for (size_t i = 0; delim[i] != '\0'; i++)
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

static size_t find_next_delim(
    const char *str,
    size_t i,
    const char *delim)
{
    while (str[i] != '\0' && !is_delim(str[i], delim))
        i++;
    if (str[i] == '\0')
        return i;
    return i + 1;
}

static size_t find_delim(
    const char *str,
    size_t i,
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
    size_t index = 0;
    size_t word_size = 0;
    char **array =
        my_malloc(sizeof(char *) * (count_delim(str, delim) + 2));

    for (size_t i = 0; str[i] != '\0'; index++) {
        printf("%lu\n", index);
        word_size = (find_delim(str, i, delim) - i + 1);
        array[index] = my_calloc((size_t)word_size, sizeof(char));
        if (is_delim(str[i], delim))
            i = find_delim(str, i, delim);
        for (size_t j = 0; !is_delim(str[i], delim) == true; j++) {
            array[index][j] = str[i];
            i++;
        }
        i = find_next_delim(str, i, delim);
    }
    array[index] = NULL;
    return array;
}
