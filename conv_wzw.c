#include <stdio.h>

// 定义卷积操作函数的内联汇编版本
//卷积核长度小于16
static inline void convolve(int *input, int *kernel, int input_length, int kernel_length, int *output) {
    // 内联汇编开始
    asm volatile (
        "loop_start:"
        "   mv s0, %0"
        "   mv s1, %1"
        "   "
        "   vsetvli t4, zero, e32\n"     // 设置向量长度为32位
        "   vlse32.v v4, (s0), %3\n"     // 将输入向量加载到向量寄存器v2中
        "   vlse32.v v8, (s1), %4\n"     // 将卷积核加载到向量寄存器v4中
        "   vwmul.vx v5, v2, v4\n"       // 对输入向量和卷积核进行逐元素乘法
        "   vredsum.vs v6, v5, v0\n"     // 对乘法结果进行逐元素求和
        "   vse32.v v6, (a0)\n"          // 将卷积操作的结果存储到输出向量中
        "   addi a0, a0, 4\n"            // 更新输出向量指针
        "   addi t3, t3, 1\n"            // 更新循环计数器
        "   blt t3, t0, loop_start\n"    // 如果还有元素需要处理，则继续循环
        : "r" (input), "r" (kernel), "r" (input_length), "r" (kernel_length), "r" (output)  // 输入寄存器
        : "s0","s1"
    );
    // 内联汇编结束
}

int main() {
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8};    // 输入向量
    int kernel[] = {1, -1, 1};                 // 卷积核
    int output[8];                             // 输出向量

    // 调用卷积操作函数
    convolve(input, kernel, 8, 3, output);

    // 打印输出向量
    printf("Output: ");
    for(int i = 0; i < 8; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}
