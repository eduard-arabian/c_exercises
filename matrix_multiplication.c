#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <cilk/cilk.h>

#define n 8192

double A[n][n];
double B[n][n];
double C[n][n];

float tdiff(struct timeval *start, struct timeval *end);

int main() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = (double)rand() / (double)RAND_MAX;
            B[i][j] = (double)rand() / (double)RAND_MAX;
            C[i][j] = 0;
        }
    }
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int s = 256;
    int t = 64;

    cilk_for (int ih = 0; ih < n; ih += s)
        cilk_for (int jh = 0; jh < n; jh += s)
            cilk_for (int kh = 0; kh < n; kh += s)
                for (int im = 0; im < s; im += t)
                    for (int km = 0; km < s; km += t)
                        for (int jm = 0; jm < s; jm += t)
                            for (int il = 0; il < t; ++il)
                                for (int kl = 0; kl < t; ++kl)
                                    for (int jl = 0; jl < t; ++jl)
                                        C[ih + im + il][jh + jm + jl]
                                            += A[ih + im + il][kh + km + kl]
                                            * B[kh + km + kl][jh + jm + jl];

    gettimeofday(&end, NULL);
    printf("%0.6f\n", tdiff(&start, &end));

    return 0;
}

float tdiff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec)
        + 1e-6 * (end->tv_usec - start->tv_usec);
}

