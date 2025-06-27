#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 選擇了malloc和free

void login() {
    char user[20]; // 定義了最大允許大小
    printf("Username: ");
    char *input = malloc(sizeof(char) * 20); // 分配記憶體並初始化
    if (input == NULL) {
        printf("記憶體分配失敗\n");
        return;
    }
    fgets(input, 20, stdin); // 使用fgets限制輸入大小
    // 檢查輸入是否包含控制字元或特殊字符，防止SQL注入
    if (input[0] == '\0') {
        printf("Username不能為空\n");
        free(input); // 釋放記憶體
        return;
    }
    // 檢查是否包含SQL特殊字符，如',", "-",等
    if (strstr(input, "\"")!= NULL || strstr(input, "'" )!= NULL) {
        printf("Username包含不允許的特殊字符\n");
        free(input);
        return;
    }
    // CWE-20: 未限制帳號來源或類型，可嘗試 SQL/特殊字元注入或過長輸入
    if (strstr(user, "admin")) {
        printf("Welcome admin\n");
    } else {
        printf("Access denied\n");
    }
    free(input); // 釋放分配的記憶體
}

int main() {
    login();
    return 0;
}
