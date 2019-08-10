#include <iostream>
#include <fcntl.h>
#include "apue.h"

#define DEFAULT_INDEX 0

using t_stat = struct stat;

int main(int argc, char **argv) {
    int fd = open("./simple_db.db", O_CREAT | O_RDWR | O_SYNC | O_APPEND);

    if (argc > 1) {
        // save to db;
        char *string = *(argv + 1);
        
        auto buf = reinterpret_cast<void*>(string);
        // append;
        ssize_t length = write(fd, buf, strlen(string));
        fsync(fd);

        if (length < 0) {
            perror(argv[DEFAULT_INDEX]);
        } else {
            std::cout << "Written(bytes): " << length << std::endl;
        }

    } else {
        // read;
        auto st = static_cast<t_stat*>(malloc(sizeof(t_stat)));
        fstat(fd, st);
        std::cout << "DB Size(bytes): " << st->st_size << std::endl;

        char buf[st->st_size];
        ssize_t length = read(fd, buf, sizeof(buf));
        if (length < 0) {
            perror(argv[DEFAULT_INDEX]);
        } else {
            std::string result(buf);
            std::cout << result << std::endl;
        }
    }

    close(fd);

    return 1;
}
