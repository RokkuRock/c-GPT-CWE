// cwe269_privilege_escalation.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void update_config() {
    FILE *f = fopen("/etc/app.conf", "w");  // CWE-269: root 權限下執行可改系統設定
    if (f) {
        fprintf(f, "config=1\n");
        fclose(f);
        printf("Updated config\n");
    } else {
        printf("Failed to update\n");
    }
}

int main() {
    // 建議: 這裡本該 drop privileges，但沒做
    update_config();
    return 0;
}
