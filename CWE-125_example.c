// cwe125_out_of_bounds_read.c
#include <stdio.h>

void show_help(int idx) {
    const char *messages[] = {
        "Start application",
        "Exit program",
        "Run diagnostics"
    };
    printf("Help: %s\n", messages[idx]);  // CWE-125: 沒有驗證索引是否越界
}

int main() {
    int choice;
    printf("Enter command number: ");
    scanf("%d", &choice);
    show_help(choice);
    return 0;
}
