#include <stdio.h>
// #include <riscv-pk/encoding.h>
// #include "marchid.h"

void convolve1D(int* signal, int signal_size, int* kernel, int kernel_size) {
    int start = kernel_size / 2;
    int end = signal_size - start;
    int output[signal_size];

    for (int i = 0; i < signal_size; i++) {
        output[i] = 0;
    }

    for (int i = start; i < end; i++) {
        for (int j = 0; j < kernel_size; j++) {
            output[i] += signal[i - start + j] * kernel[j];
        }
    }

    for (int i = 0; i < signal_size; i++) {
        printf("%d ", output[i]);
    }
}


void convolve2D(int** signal, int signal_height, int signal_width, int** kernel, int kernel_height, int kernel_width) {
    int start_h = kernel_height / 2;
    int start_w = kernel_width / 2;
    int end_h = signal_height - start_h;
    int end_w = signal_width - start_w;
    int output[signal_height][signal_width];

    for (int i = 0; i < signal_height; i++) {
        for (int j = 0; j < signal_width; j++) {
            output[i][j] = 0;
        }
    }

    for (int i = start_h; i < end_h; i++) {
        for (int j = start_w; j < end_w; j++) {
            for (int m = 0; m < kernel_height; m++) {
                for (int n = 0; n < kernel_width; n++) {
                    output[i][j] += signal[i - start_h + m][j - start_w + n] * kernel[m][n];
                }
            }
        }
    }

    for (int i = 0; i < signal_height; i++) {
        for (int j = 0; j < signal_width; j++) {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
   // 一维卷积测试用例
   int signal1D[5] = {1, 2, 3, 4, 5};
   int kernel1D[3] = {1, 0, -1};
   printf("一维卷积结果：\n");
   convolve1D(signal1D, 5, kernel1D, 3);
   printf("\n");

   // 二维卷积测试用例
   int signal2D[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   int kernel2D[2][2] = {{-1, -2}, {-3, -4}};
   int* signal2D_ptrs[3] = {signal2D[0], signal2D[1], signal2D[2]};
   int* kernel2D_ptrs[2] = {kernel2D[0], kernel2D[1]};
   printf("二维卷积结果：\n");
   convolve2D(signal2D_ptrs, 3, 3, kernel2D_ptrs, 2, 2);
   return 0;
}
