#include <math.h>
#include "generic_type.h"

const char *type_to_string(TYPE type) {
    switch (type) {
        case GENERIC_TYPE_T_TYPE_DOUBLE:
            return "double";
        case GENERIC_TYPE_T_TYPE_INT:
            return "int";
        case GENERIC_TYPE_T_TYPE_STRING:
            return "string";
        case GENERIC_TYPE_T_TYPE_BOOL:
            return "bool";
        default:
            return "unknown";
    }
}

TYPE generic_type_t_get_type(generic_type_t x) {
    if (!isnan(x)) {
        return GENERIC_TYPE_T_TYPE_DOUBLE;
    }
    union {
        generic_type_t d;
        unsigned long long i;
    } u = { .d = x };
    return (TYPE)((u.i >> 48) & 0x0007);
}

generic_type_t int_to_generic_type_t(int x) {
    const unsigned long long SHIFTED_GENERIC_TYPE = ((unsigned long long)GENERIC_TYPE_T_TYPE_INT << 48) & 0x7000000000000;
    union {
        generic_type_t d;
        unsigned long long i;
    } u = { .i = 0x7ff8000000000000ULL | *(unsigned int*)&x | SHIFTED_GENERIC_TYPE};
    return u.d;
}

int generic_type_t_to_int(generic_type_t x) {
    union {
        generic_type_t d;
        unsigned long long i;
    } u = { .d = x };
    return (int)(u.i & 0xffffffffffff);
}

generic_type_t double_to_generic_type_t(double x)
{
    if (isnan(x)) {
        union {
            generic_type_t d;
            unsigned long long i;
        } u = { .i = 0xfff8000000000000ULL | *(unsigned long long*)&x};
        return u.d;
    }
    return x;
}

double generic_type_t_to_double(generic_type_t x)
{
    return x;
}

generic_type_t string_to_generic_type_t(const char *x)
{
    const unsigned long long SHIFTED_GENERIC_TYPE = ((unsigned long long)GENERIC_TYPE_T_TYPE_STRING << 48) & 0x7000000000000;
    union {
        generic_type_t d;
        unsigned long long i;
    } u = { .i = 0x7ff8000000000000ULL | (unsigned long long)x | SHIFTED_GENERIC_TYPE};
    return u.d;
}

const char *generic_type_t_to_string(generic_type_t x)
{
    union {
        generic_type_t d;
        unsigned long long i;
    } u = { .d = x };
    return (const char *)(u.i & 0xffffffffffff);
}

generic_type_t bool_to_generic_type_t(bool x)
{
    const unsigned long long SHIFTED_GENERIC_TYPE = ((unsigned long long)GENERIC_TYPE_T_TYPE_BOOL << 48) & 0x7000000000000;
    union {
        generic_type_t d;
        unsigned long long i;
    } u = { .i = 0x7ff8000000000000ULL | (unsigned long long)x | SHIFTED_GENERIC_TYPE};
    return u.d;
}

bool generic_type_t_to_bool(generic_type_t x)
{
    union {
        generic_type_t d;
        unsigned long long i;
    } u = { .d = x };
    return (bool)(u.i & 0xffffffffffff);
}