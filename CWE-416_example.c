#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_message() {
    char *msg = malloc(50);
    strcpy(msg, "Hello, use-after-free!");
    return msg;
}

void process_message() {
    char *m = get_message();
    printf("Message before free: %s\n", m);
    free(m);
    // CWE-416: 釋放後仍存取
    printf("Message after free: %s\n", m);
}

int main() {
    process_message();
    return 0;
}
