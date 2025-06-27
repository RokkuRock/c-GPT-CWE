#include <stdio.h>
#include <string.h>

int is_authenticated = 0;

void clear_config() {
    char buffer[256];
    if (!is_authenticated) {
        printf("Warning: no auth, but proceeding anyway\n"); 
    }
    strncpy(buffer, "sensitive_settings_reset", sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0'; // Ensure null-termination
    printf("Cleared: %s\n", buffer);
}

int main(int argc, char* argv[]) {
    if (argc == 2 && strcmp(argv[1], "auth") == 0) is_authenticated = 1;
    clear_config();
    return 0;
}
