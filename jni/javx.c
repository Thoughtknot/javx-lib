#include "org_javx_Javx.h"
#include "../src/simd.h"
#include <stdlib.h>

int32_t* convert_int_array(JNIEnv* env, jintArray* arr, int size) {
    jint* c_arr = (*env)->GetIntArrayElements(env, *arr, 0);
    int32_t* c_t = (int32_t*) malloc(size * sizeof(int32_t));
    for (int i = 0; i < size; ++i) {
        c_t[i] = (int32_t) c_arr[i];
    }
    (*env)->ReleaseIntArrayElements(env, *arr, c_arr, 0);
    return c_t;
}

jintArray convert_jint_array(JNIEnv * env, int32_t* arr, int size) {
    if (arr == NULL) {
        return NULL;
    }
    jintArray ret;
    ret = (*env)->NewIntArray(env, size);
    jint jarr[size];
    for (int i = 0; i < size; ++i) {
        jarr[i] = arr[i];
    }
    (*env)->SetIntArrayRegion(env, ret, 0, size, jarr);
    free(arr);
    return ret;
}

JNIEXPORT jintArray JNICALL Java_org_javx_Javx_add_1int(JNIEnv * env, jobject obj, jintArray a, jintArray b) {
    int size = (*env)->GetArrayLength(env, a);
    
    jint* c_arr_a = (*env)->GetIntArrayElements(env, a, 0);
    int32_t aArray[size];
    for (int i = 0; i < size; ++i) {
        aArray[i] = (int32_t) c_arr_a[i];
    }
    (*env)->ReleaseIntArrayElements(env, a, c_arr_a, 0);

    jint* c_arr_b = (*env)->GetIntArrayElements(env, b, 0);
    int32_t bArray[size];
    for (int i = 0; i < size; ++i) {
        bArray[i] = (int32_t) c_arr_b[i];
    }
    (*env)->ReleaseIntArrayElements(env, b, c_arr_b, 0);
    int32_t* res = add_int(aArray, bArray, size);
    jintArray ret = convert_jint_array(env, res, size);
    return ret;
}