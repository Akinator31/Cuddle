#include "dataframe.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/cdefs.h>

static bool check_int_downcast(
    column_t *column,
    size_t nb_rows)
{
    char **content = column->content_strings;
    char *tmp = NULL;
    size_t dot_pos = 0;

    if (column->type == BOOL)
        return true;
    for (size_t i = 0; i < nb_rows; i++) {
        tmp = content[i];
        if (tmp[0] == '-')
            tmp++;
        dot_pos = strcspn(tmp, ".");
        if (!str_isdigit(tmp, dot_pos - 1))
            return false;
        tmp += dot_pos;
        if (!str_isdigit(tmp, strlen(tmp)))
            return false;
    }
    return true;
}

static bool check_uint_downcast(
    column_t *column,
    size_t nb_rows)
{
    char **content = column->content_strings;
    char *tmp = NULL;
    size_t dot_pos = 0;

    if (column->type == BOOL)
        return true;
    for (size_t i = 0; i < nb_rows; i++) {
        tmp = content[i];
        dot_pos = strcspn(tmp, ".");
        if (!str_isdigit(tmp, dot_pos))
            return false;
        tmp += dot_pos + 1;
        if (!str_isdigit(tmp, strlen(tmp)))
            return false;
    }
    return true;
}

// Assumes only numerical values, strings will always evaluate to true
// since they forcefully exist. Furthermore, any numerical value can logically
// become a bool, as such, we always return true;
static bool check_bool_downcast(
    __attribute__((unused))column_t *column,
    __attribute__((unused))size_t nb_rows)
{
    return true;
}

// Int and Float have the same requirements to get downcasted
bool check_downcast(
    column_t *column,
    column_type_t downcast,
    size_t nb_rows)
{
    bool can_downcast = false;

    if (downcast == INT || downcast == FLOAT)
        can_downcast = check_int_downcast(column, nb_rows);
    if (downcast == UINT)
        can_downcast = check_uint_downcast(column, nb_rows);
    if (downcast == BOOL)
        can_downcast = check_bool_downcast(column, nb_rows);
    return can_downcast;
}
