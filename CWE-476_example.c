// cwe476_null_deref.c
#include <stdio.h>

void print_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    char buf[100];
    fgets(buf, sizeof(buf), f);  // CWE-476: f 可能為 NULL
    printf("Content: %s\n", buf);
    fclose(f);
}

int main() {
    char fname[100];
    printf("File to read: ");
    scanf("%s", fname);
    print_file(fname);
    return 0;
}
