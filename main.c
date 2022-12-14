#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "generic_type.h"

void test_positive_int();
void test_negative_int();
void test_positive_double();
void test_negative_double();
void test_nan_double();
void test_string();
void test_true_bool();
void test_false_bool();

int main() {
    test_positive_int();
    test_negative_int();
    test_positive_double();
    test_negative_double();
    test_nan_double();
    test_string();
    test_true_bool();
    test_false_bool();
    return 0;
}

void test_positive_int()
{
    int x = 3;
    generic_type_t y = int_to_generic_type_t(x);
    assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_INT);
    int z = generic_type_t_to_int(y);
    assert(x == z);
    printf("%d -> %f (type = %s) -> %d\n", x, y, type_to_string(generic_type_t_get_type(y)), z);
}

void test_negative_int()
{
    int x = -3;
    generic_type_t y = int_to_generic_type_t(x);
    assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_INT);
    int z = generic_type_t_to_int(y);
    assert(x == z);
    printf("%d -> %f (type = %s) -> %d\n", x, y, type_to_string(generic_type_t_get_type(y)),z);
}

void test_positive_double()
{
    double x = 3.0;
    generic_type_t y = double_to_generic_type_t(x);
    assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_DOUBLE);
    double z = generic_type_t_to_double(y);
    assert(x == z);
    printf("%lf -> %f (type = %s) -> %lf\n", x, y, type_to_string(generic_type_t_get_type(y)), z);
}

void test_nan_double()
{
    double x = NAN;
    generic_type_t y = double_to_generic_type_t(x);
    assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_DOUBLE);
    double z = generic_type_t_to_double(y);
    assert(isnan(z)); // NAN != NAN
    printf("%lf -> %f (type = %s) -> %lf\n", x, y, type_to_string(generic_type_t_get_type(y)), z);
}

void test_negative_double()
{
    double x = -3.0;
    generic_type_t y = double_to_generic_type_t(x);
    assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_DOUBLE);
    double z = generic_type_t_to_double(y);
    assert(x == z);
    printf("%lf -> %f (type = %s) -> %lf\n", x, y, type_to_string(generic_type_t_get_type(y)), z);
}

void test_string()
{
    const char *x = "hello";
    generic_type_t y = string_to_generic_type_t(x);
    assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_STRING);
    const char *z = generic_type_t_to_string(y);
    assert(strcmp(x, z) == 0);
    printf("%s -> %f (type = %s) -> %s\n", x, y, type_to_string(generic_type_t_get_type(y)), z);
}

void test_true_bool()
{
    bool x = true;
    generic_type_t y = bool_to_generic_type_t(x);
    assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_BOOL);
    bool z = generic_type_t_to_bool(y);
    assert(x == z);
    printf("%s -> %f (type = %s) -> %s\n", x ? "true" : "false", y, type_to_string(generic_type_t_get_type(y)), z ? "true" : "false");
}

void test_false_bool()
{
    bool x = false;
    generic_type_t y = bool_to_generic_type_t(x);
    assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_BOOL);
    bool z = generic_type_t_to_bool(y);
    assert(x == z);
    printf("%s -> %f (type = %s) -> %s\n", x ? "true" : "false", y, type_to_string(generic_type_t_get_type(y)), z ? "true" : "false");
}