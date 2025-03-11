/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#ifndef LIB_H
    #define LIB_H

    #include <stddef.h>
    #include <stdio.h>

char **str_to_word_array(const char *str, const char *delim);
void print_str_array(char **array);
size_t str_array_len(char **array);
void *free_str_array(char **array);

// getline wrapper to remove newline characters
ssize_t getlinex(
    char **restrict lineptr,
    FILE *restrict stream);

char **line_to_row(
    const char *line,
    const char *delimiters,
    size_t *rows_count);

char *clean_str(char *str);

#endif /* LIB_H */
