# C generic types

---

Tired of typing in C? Use the generic type `generic_type_t` to make your code less readable.

It takes the same size in memory than a double.

In case inside value is a double, it will be casted to a double.
Otherwise, the internal value will be a NAN (Not a Number), and we take advantage of the fact that NAN can contain 51 bits of data.
The first 3 bits are used to store the type of the value, and the remaining 48 bits are used to store the value. The value is a pointer in case of string, and the value is stored directly into these bits otherwise.

## Example

```c
int x = 3;
generic_type_t y = int_to_generic_type_t(x);
assert(generic_type_t_get_type(y) == GENERIC_TYPE_T_TYPE_INT);
int z = generic_type_t_to_int(y);
assert(x == z);
```