/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** I hate manual frees
*/

#ifndef GARBAGE_COLLECTOR_H
    #define GARBAGE_COLLECTOR_H

    #include <stddef.h>

    #define ADD_MODE 0
    #define MODIF_MODE 1
    #define FREE_MODE 2

void *my_malloc(size_t bytes);
void *my_calloc(size_t nitems, size_t size);
void *my_realloc(void *ptr, size_t size, size_t old_size);
void *my_reallocarray(void *ptr, size_t nmemb, size_t size);
void free_garbage(void);
char *my_strdup(const char *str);

void collect_garbage(
    void *ptr,
    void *old_ptr,
    int mode);

#endif /* GARBAGE_COLLECTOR_H */
