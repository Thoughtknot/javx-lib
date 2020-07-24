#include <check.h>
#include "../src/simd.h"
#include <stdlib.h>
#include <stdio.h>

START_TEST (test_simd_basic)
{
    int32_t a1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int32_t b1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int32_t* c1 = add_int(a1, b1, 8);

    int32_t a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int32_t b[] = {11, 12, 13, 14, 15, 16, 17, 18, 1, 2, 3, 4, 5, 6, 7, 8};
    int32_t* c = add_int(a, b, 16);

    int32_t a2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 4, 5, 6, 7, 8, 9, 10, 11};
    int32_t b2[] = {11, 12, 13, 14, 15, 16, 17, 18, 1, 2, 3, 4, 5, 6, 7, 8, 4, 5, 6, 7, 8, 9, 10, 11};
    int32_t* c2 = add_int(a2, b2, 24);
    printf("%i, %i, %i, %i, %i, %i\n", c1[0], c1[4], c[0], c[12], c2[0], c2[17]);
}
END_TEST

Suite * suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("simd");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_simd_basic);
    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}