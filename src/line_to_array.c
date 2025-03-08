/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "garbage_collector.h"

static size_t count_delimiters(
    const char *str,
    const char *delimiters)
{
    size_t count = 0;

    for (size_t i = 0; str[i]; i++)
        if (strchr(delimiters, str[i]))
            count++;
    return count;
}

char *quote_strdup(
    const char *string,
    const char *delimiters)
{
    char *word = NULL;
    size_t word_len = 0;

    word_len = strcspn(string, delimiters);
    if (string[0] == '"')
        word_len = strcspn(&string[1], "\"") + 2;
    if (word_len == 0)
        return strdup("");
    word = strndup(string, word_len);
    return word;
}

char **line_to_row(
    const char *line,
    const char *delimiters)
{
    char **row = NULL;
    size_t max_words = 0;

    max_words = count_delimiters(line, delimiters);
    row = my_calloc(count_delimiters(line, delimiters) + 2, sizeof(char *));
    for (size_t i = 0; i < max_words + 1; i++) {
        row[i] = quote_strdup(line, delimiters);
        line = &line[strlen(row[i]) + 1];
    }
    return row;
}
