extern int memcmp(const void *u, const void *v, int n);
extern int vector_init();

int main() {
    vector_init();
    char str1[] = "abcd";
    char str2[] = "abcd";
    char str3[] = "abce";

    int result1 = memcmp(str1, str2, 4);
    int result2 = memcmp(str1, str3, 4);

    if (result1 != 0) {
        return 1;
    } 

    if (result2 == 0) {
        return 2;
    } 

    return 0;
}
