#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#define ITERS 1000

typedef unsigned long long ticks;

void writeLLUArray(char* f_name, ticks* vec, unsigned n) {
    FILE *fp;
    fp = fopen(f_name, "w");
    int i = 0;

    for (; i < n; ++i)
        fprintf(fp, "%llu\n", vec[i]);
    fclose(fp);
}

void writeXYZ(char* f_name, int m, int n, int* x_list, int* y_list, float z_mat[m][n]) {
    FILE *fp;
    fp = fopen(f_name, "w");

    int i = 0;
    for (; i < m; ++i) {
        int j = 0;
        for (; j < n; ++j) {
            fprintf(fp, "%d\t%d\t%f\n", x_list[i], y_list[j], z_mat[i][j]);
        }
    }
    fclose(fp);

}

#endif // UTILS_H
