/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#ifndef LIB_H
    #define LIB_H

    #include <stddef.h>

char **str_to_word_array(const char *str, const char *delim);
void print_array(char **array);
size_t str_array_len(char **array);

#endif /* LIB_H */
