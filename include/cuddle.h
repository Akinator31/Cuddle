/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#ifndef INCLUDED_CUDDLE_H
    #define INCLUDED_CUDDLE_H

    #include <stdbool.h>

// allows for strings to be quoted and count as a single value
    #define CSV_QUOTED_STRINGS true
// allows for values to be separated from the separators with spaces
    #define CSV_SPACED_VALUE false
// allows for floats to start directly by a dot
    #define CSV_DOTED_FLOATS true
// Writes output to stderr
    #define ERROR_OUTPUT false

// Structure alignment
    #define PACKED __attribute__((packed))

// File modes
    #define READ_ONLY "r"

    #define EMPTY_STRING ""

#endif
