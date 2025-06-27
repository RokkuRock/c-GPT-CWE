// cwe20_input_validation.c
#include <stdio.h>
#include <string.h>

void login() {
    char user[20];
    printf("Username: ");
    scanf("%s", user);
    // CWE-20: 未限制帳號來源或類型，可嘗試 SQL/特殊字元注入或過長輸入
    if (strstr(user, "admin")) {
        printf("Welcome admin\n");
    } else {
        printf("Access denied\n");
    }
}

int main() {
    login();
    return 0;
}
