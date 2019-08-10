#include <iostream>
#include <string>
#include "apue.h"
#include <fcntl.h>

#define DEFAULT_INDEX 0

int main(int argc, char **argv) {
    int fd = open("./read.cc", O_RDONLY);

    char buf[1024];
    // signed size_t, in case -1;
    ssize_t length = read(fd, buf, 1024);

    if (length > 0) {
        std::string str(buf);
        std::cout << str << std::endl;
    } else {
        // error occur;
        perror(argv[DEFAULT_INDEX]);
    }

    return 1;
}