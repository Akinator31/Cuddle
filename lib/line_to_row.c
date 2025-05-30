/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "garbage_collector.h"
#include "lib.h"
#include "cuddle.h"

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

static char *quote_strdup(
    const char *string,
    const char *delimiters)
{
    size_t word_len = 0;
    bool quoted = false;

    if (CSV_QUOTED_STRINGS)
        if (string[0] == '"') {
            word_len = strcspn(&string[1], "\"") + 2;
            quoted = true;
        }
    word_len += strcspn(&string[word_len - quoted], delimiters) - quoted;
    if (word_len == 0)
        return strdup("");
    return strndup(string, word_len);
}

// switch to some kind of custom strtok with no memory allocation
char **line_to_row(
    const char *line,
    const char *delimiters,
    size_t *column_count)
{
    char **row = NULL;
    size_t max_words = 0;

    max_words = count_delimiters(line, delimiters);
    row = calloc(max_words + 2, sizeof(char *));
    for (*column_count = 0; *column_count < max_words + 1 && *line;
        (*column_count)++) {
        row[*column_count] = quote_strdup(line, delimiters);
        line = &line[strlen(row[*column_count])];
        if (line[0] != '\0')
            line++;
    }
    return row;
}
