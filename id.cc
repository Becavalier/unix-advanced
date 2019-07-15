#include <iostream>
#include "apue.h"

int main(int argc, char **argv) {
    std::cout << "PID: " << getpid() << std::endl;
    std::cout << "UID: " << getuid() << std::endl;
    return 1;
}