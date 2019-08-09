#include <iostream>
#include <fcntl.h>
#include "apue.h"

#define DEFAULT_INDEX 0

int main(int argc, char **argv) {
    int fd = open("./sync.txt", O_CREAT | O_APPEND | O_WRONLY);

    char buf[] = "Hello, world!";
    ssize_t length = write(fd, buf, sizeof(buf) - 1);

    if (length < 0) {
        perror(argv[DEFAULT_INDEX]);
        return 0;
    }

    // put the transaction into the buffer queue;
    sync();

    // waiting for system to complete the transaction;
    int result = fsync(fd);

    // 0:ok, -1:error;
    std::cout << result << std::endl;

    return 1;
}