
void convolution(int input[], int kernel[], int output[], int input_size, int kernel_size) {
    int i, j;

    for (i = 0; i < input_size + kernel_size - 1; i++)
        output[i] = 0;

    for (i = 0; i < input_size; i++) {
        for (j = 0; j < kernel_size; j++) {
            output[i+ j] += input[i] * kernel[j];
        }
    }
}
