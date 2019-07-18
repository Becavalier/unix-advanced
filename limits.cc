#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "apue.h"

using namespace std;

int main(int argc, char **argv) {
    // reset;
    errno = 0;

    cout << UCHAR_MAX << endl;
    cout << FOPEN_MAX << endl;
    cout << PATH_MAX << endl;

    // runtime restrict;
    const char* filePath = "./limits.cc";
    const auto fileHandler = open(filePath, O_RDONLY);

    cout << sysconf(_SC_ARG_MAX) << endl;
    cout << pathconf(filePath, _PC_NAME_MAX) << endl;
    cout << fpathconf(fileHandler, _PC_NAME_MAX) << endl;

    close(fileHandler);
    // errno = EINVAL;
    if (sysconf(999l) < 0 && errno == EINVAL) {
        perror(argv[0]);
    }
}   