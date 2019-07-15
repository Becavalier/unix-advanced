#include "apue.h"
#include <iostream>

#define BUFFERSIZE 4096

int main(int argc, char** argv) {
    int n;
    char buf[BUFFERSIZE];

    while((n = read(STDIN_FILENO, buf, BUFFERSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            std::cerr << "[duplicate] write error!" << std::endl;
        }
    }
    
    if (n < 0) {
        std::cerr << "[duplicate] read error!" << std::endl;
    }
        
    return 0;
}
