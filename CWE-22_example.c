#include <stdio.h>
#include <stdlib.h>

void read_file(const char *filename) {
    char path[512] = "data/";
    strcat(path, filename); 
    FILE *f = fopen(path, "r");
    if (!f) { perror("fopen"); return; }
    char buf[100];
    fgets(buf, sizeof(buf), f);
    printf("First line: %s\n", buf);
    fclose(f);
    f = NULL; // 確保文件指針不再被使用
}

int main(int argc, char* argv[]) {
    if (argc < 2) { printf("usage: %s <file>\n", argv[0]); return 1; }
    read_file(argv[1]);
    return 0;
}
