.PHONY: jni

make:
	gcc -Wall src/simd.c -c -march=native -o simd.o

jni:
	gcc -fPIC -Wpsabi src/simd.c -c -march=native -o libsimd.o
	gcc -fPIC jni/javx.c -march=native -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/linux" -shared  libsimd.o -o libjavx.so
	
jni_windows:
	gcc -fPIC src/simd.c -c -march=native -o libsimd.o
	gcc -fPIC jni/javx.c -march=native -I"${JAVA_HOME}/include" -I"${JAVA_HOME}/include/win32" -shared  libsimd.o -o javx.dll

check:
	gcc test/check_simd.c -c -o test/check_simd.o
	gcc simd.o test/*.o -o test_suite `pkg-config --cflags --libs check`
	./test_suite
