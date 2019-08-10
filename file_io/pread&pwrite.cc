#include <iostream>
#include <string>
#include "apue.h"
#include <fcntl.h>

#define DEFAULT_INDEX 0

int main(int argc, char **argv) {
    char buf[1024];

    int fd = open("./pread&pwrite.cc", O_RDWR);
    if (fd > 0) {
        // it's atomic, lseek and read (transaction);
        ssize_t length = pread(fd, buf, 1024, 100);
        
        std::string code(buf);
        std::cout << code << std::endl;
    } else {
        perror(argv[DEFAULT_INDEX]);
    }
    
    int fd_create = open("./pread&pwrite.txt", O_RDWR | O_CREAT | O_APPEND);
    if (fd_create > 0) {
        // the same atomic operation, lseek and write;
        ssize_t length = pwrite(fd_create, buf, strlen(buf), DEFAULT_INDEX);

        if (length > 0) {
            std::cout << length << std::endl;
        } else {
            perror(argv[DEFAULT_INDEX]);
        }
    }

    fsync(fd_create);

    return 1;
}
