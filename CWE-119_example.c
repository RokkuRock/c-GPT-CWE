#include <stdio.h>
#include <string.h>

void add_comment() {
    char comment[50];
    printf("Leave a comment: ");
    fgets(comment, 512, stdin);  
    printf("Your comment: %s\n", comment);
}

int main() {
    add_comment();
    return 0;
}
