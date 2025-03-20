/*
** EPITECH PROJECT, 2025
** my_stype
** File description:
** Checks if a string is only made of digits
*/

#include "utils.h"
#include <ctype.h>
#include <string.h>

int str_isdigit(char *str, size_t len)
{
    for (size_t i = 0; i < len; i++)
        if (!isdigit(str[i]))
            return 0;
    return 1;
}
