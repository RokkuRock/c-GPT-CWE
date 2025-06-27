// cwe190_int_overflow.c
#include <stdio.h>
#include <stdlib.h>

void alloc_array() {
    unsigned int count;
    printf("How many elements? ");
    scanf("%u", &count);
    // CWE-190: 未檢查乘法溢位，可能導致分配記憶體過小
    int *arr = malloc(count * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        return;
    }
    arr[0] = 123;
    printf("First = %d\n", arr[0]);
    free(arr);
}

int main() {
    alloc_array();
    return 0;
}
