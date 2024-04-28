#include <stdio.h>
#include <riscv-pk/encoding.h>
// 定义卷积函数
void convolution(int input[], int kernel[], int output[], int input_size, int kernel_size);


int main() {
    int input[] = {1, 2, 3, 4, 5};
    int kernel[] = {1, 2, };
    int output[7]; // 输出数组大小为 input_size + kernel_size - 1

    // 计算卷积
    convolution(input, kernel, output, 5, 3);

    // 打印卷积结果
    printf("Convolution result: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", output[i]);
    }
    return 0;
}
