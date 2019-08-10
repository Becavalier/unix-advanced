#include <iostream>
#include <string>
#include <fcntl.h>
#include "apue.h"

#define DEFAULT_INDEX 0

int main(int argc, char **argv) {
    int fd = open("./dup&dup2.cc", O_RDONLY);
    int fd_read = open("./read.cc", O_RDONLY);

    // "dup" will reset the "FD_CLOEXEC" flag to 0;
    std::cout << dup(fd) << std::endl;

    char buf[1024];

    // the same as `close(fd_read)`, then `fcntl(fd, F_DUPFD, fd_read)`;
    // "dup2" is also an atomic operation;
    ssize_t length = read(dup2(fd, fd_read), buf, sizeof(buf));
    if (length > 0) {
        std::string code(buf);
        std::cout << code << std::endl;
    } else {
        perror(argv[DEFAULT_INDEX]);
    }

    return 1;
}
