#include <iostream>
#include "apue.h"
#include <fcntl.h>

#define DEFAUL_INDEX 0

int main(int argc, char **argv) {
    int fd = open("./write.txt", O_APPEND | O_CREAT | O_WRONLY);
    
    char content[] = "Hello, world!";
    ssize_t length = write(fd, content, sizeof(content) - 1);

    if (length > 0) {
        std::cout << length << std::endl;
    } else {
        perror(argv[DEFAUL_INDEX]);
    }

    return 1;
}