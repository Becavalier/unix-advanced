#include "apue.h"
#include <iostream>

using stat_type = struct stat;

int main(int argc, char** argv) {
    int n;

    auto stat_buf = static_cast<stat_type*>(malloc(sizeof(stat_type)));
    fstat(STDIN_FILENO, stat_buf);

    // set the buffer size the same as file block size;
    char buf[stat_buf->st_blksize];

    while((n = read(STDIN_FILENO, buf, stat_buf->st_blksize)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            std::cerr << "[duplicate] write error!" << std::endl;
        }
    }
    
    if (n < 0) {
        std::cerr << "[duplicate] read error!" << std::endl;
    }
        
    return 0;
}
