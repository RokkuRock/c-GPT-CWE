#include <stdio.h>
#include <stdlib.h>

union Data { int i; short *s; };

short* get_buffer() {
    short *p = malloc(5 * sizeof(short));
    for (int i = 0; i < 5; i++) p[i] = i;
    return p;
}

void do_confusion() {
    union Data d;
    d.s = get_buffer();
    d.i = 12345; // CWE‑843: 覆寫原本為指標的 union 欄位
    printf("Accessing as pointer -> %d\n", d.s[0]); // 未定義行為
}

int main() {
    do_confusion();
    return 0;
}
