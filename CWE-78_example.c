#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_dir() {
    char cmd[256] = "ls ";
    char dir[200];
    printf("Which dir to list? ");
    fgets(dir, sizeof(dir), stdin);
    dir[strcspn(dir, "\n")] = 0;
    strcat(cmd, dir); 
    system(cmd);
}

int main() {
    list_dir();
    return 0;
}
