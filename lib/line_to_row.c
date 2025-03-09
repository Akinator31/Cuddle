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

#if defined(CSV_QUOTED_STRINGS)
    if (string[0] == '"')
        word_len = strcspn(&string[1], "\"") + 2;
#endif
    word_len += strcspn(&string[word_len], delimiters);
    if (word_len == 0)
        return my_strdup("");
    return my_strndup(string, word_len);
}

char **line_to_row(
    const char *line,
    const char *delimiters,
    size_t *column_count)
{
    char **row = NULL;
    size_t max_words = 0;

    max_words = count_delimiters(line, delimiters);
    row = my_calloc(max_words + 2, sizeof(char *));
    for (*column_count = 0; *column_count < max_words + 1 && *line; (*column_count)++) {
        row[*column_count] = quote_strdup(line, delimiters);
        line = &line[strlen(row[*column_count]) + 1];
    }
    return row;
}
