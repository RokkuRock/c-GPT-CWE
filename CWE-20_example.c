#include <stdio.h>
#include <string.h>

void login() {
    char user[20];
    printf("Username: ");
    scanf("%s", user);
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
