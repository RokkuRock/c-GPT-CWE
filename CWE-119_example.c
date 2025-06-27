#include <stdio.h>
#include <string.h>

void add_comment() {
    char comment[512];
    printf("Leave a comment: ");
    fgets(comment, sizeof(comment), stdin);  
    printf("Your comment: %s\n", comment);
}

int main() {
    add_comment();
    return 0;
}
