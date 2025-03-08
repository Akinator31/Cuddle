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

// getline wrapper to remove newline characters
ssize_t getlinex(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);

#endif /* LIB_H */
