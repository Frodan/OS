#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int integer;
    float float_number;
    double double_number;
    integer = INT_MAX;
    float_number = FLT_MAX;
    double_number = DBL_MAX;
    printf("Int max: %d, size of int: %d.\n", integer, sizeof(integer));
    printf("Float max: %f, size of float: %d.\n", float_number, sizeof(float_number));
    printf("Double max: %f, size of double: %d.\n", double_number, sizeof(double_number));
    return 0;
}