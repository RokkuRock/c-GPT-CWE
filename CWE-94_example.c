#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eval_expr(const char *expr) {
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "echo $((%s))", expr);
    system(cmd);
}

int main() {
    char expr[200];
    printf("Enter number calc (e.g., 1+2*3): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;
    eval_expr(expr);
    return 0;
}
