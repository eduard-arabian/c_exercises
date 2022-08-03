#include <stdio.h>

#ifdef __AVX__
  #include <immintrin.h>
#else
  #warning No AVX support - will not compile
#endif

int main() {

    __m256d a = _mm256_set_pd(4.0, 3.0, 2.0, 1.0);
    __m256d b = _mm256_set_pd(14.0, 13.0, 12.0, 11.0);

    __m256d c = _mm256_add_pd(a, b);

    double d[8];
    _mm256_storeu_pd(d, c);

    printf("Result equals ");
    for (int i = 0; i < 3; i++)
        printf("%.0lf, ", d[i]);
    printf("%.0f\n", d[3]);

    return 0;
}
