#include <x86intrin.h>
#include <stdio.h>
#include <string.h>
#include "simd.h"

int32_t* add_int(int32_t*a, int32_t* b, int size) {
    if (size % 8 != 0) {
        return NULL;
    }
    int32_t* ret = (int32_t*) malloc(size * sizeof(int32_t));
    for (int i = 0; i < size/8; ++i) {
        int row = i*8;
        __m256i aI = _mm256_setr_epi32(
            a[0 + row], a[1 + row], 
            a[2 + row], a[3 + row], 
            a[4 + row], a[5 + row], 
            a[6 + row], a[7 + row]);
        __m256i bI = _mm256_setr_epi32(
            b[0 + row], b[1 + row], 
            b[2 + row], b[3 + row], 
            b[4 + row], b[5 + row], 
            b[6 + row], b[7 + row]);
        __m256i cI = _mm256_add_epi32(aI, bI);
        memcpy(&ret[row], &cI, 8 * sizeof(int32_t));
    }
    return ret;
}