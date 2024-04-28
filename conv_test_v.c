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
    // 测试用例：输入和卷积核的尺寸都较大
    int input[30][30];
    int kernel[3][3] = {
        {1, 0, -1},
        {0, 1, 0},
        {-1, 0, 1}
    };
    int* input_ptrs[30];
    int* kernel_ptrs[3] = {kernel[0], kernel[1], kernel[2]};
    int output[28][28];
    int* output_ptrs[28];

    // 初始化输入矩阵和指针数组
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            input[i][j] = i * j;
        }
        input_ptrs[i] = input[i];
        if (i < 28) {
            output_ptrs[i] = output[i];
        }
    }

    convolve2D(input_ptrs, 30, 30, kernel_ptrs, 3, 3);

    // 打印结果
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}
