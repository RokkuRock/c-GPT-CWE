// cwe362_race_condition.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void write_log(const char *msg) {
    int fd = open("log.txt", O_WRONLY | O_CREAT, 0666);
    write(fd, msg, strlen(msg));  // CWE-362: 未加鎖，並發寫入時可能資料競爭
    close(fd);
}

int main() {
    write_log("Process A start\n");
    return 0;
}
