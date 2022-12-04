#ifndef GENERIC_TYPES_GENERIC_TYPE_H
#define GENERIC_TYPES_GENERIC_TYPE_H

#include <stdbool.h>

typedef double generic_type_t;

typedef enum generic_type_t_type {
    GENERIC_TYPE_T_TYPE_DOUBLE = 0,
    GENERIC_TYPE_T_TYPE_INT,
    GENERIC_TYPE_T_TYPE_STRING,
    GENERIC_TYPE_T_TYPE_BOOL,
} TYPE;

const char *type_to_string(TYPE type);

TYPE generic_type_t_get_type(generic_type_t x);

generic_type_t double_to_generic_type_t(double x);
double generic_type_t_to_double(generic_type_t x);

generic_type_t int_to_generic_type_t(int x);
int generic_type_t_to_int(generic_type_t x);

generic_type_t string_to_generic_type_t(const char *x);
const char *generic_type_t_to_string(generic_type_t x);

generic_type_t bool_to_generic_type_t(bool x);
bool generic_type_t_to_bool(generic_type_t x);

#endif //GENERIC_TYPES_GENERIC_TYPE_H
