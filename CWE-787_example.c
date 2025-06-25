#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void record_name() {
    char *buf = malloc(20);
    if (!buf) return;
    printf("Enter your name (<50 chars): ");
    fgets(buf, 100, stdin); // CWE‑787: 讀入超過 buf 可用大小
    buf[strcspn(buf, "\n")] = 0;
    printf("Recorded name: %s\n", buf);
    free(buf);
}

int main() {
    record_name();
    return 0;
}
