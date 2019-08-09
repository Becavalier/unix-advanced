#include <iostream>
#include <fcntl.h>
#include "apue.h"

#define _FILE_OFFSET_BITS 64

using namespace std;

int main(int argc, char **argv) {
    // int fd = open(STDIN_FILENO, O_RDWR | O_APPEND);

    // STDIN_FILENO was already a fd;
    off_t offset = lseek(STDIN_FILENO, -10, SEEK_END);
    
    // reset error indicator;
    errno = 0;
    // error occur;
    if (offset == -1) {
        perror(argv[0]);
    } else {
        cout << offset << endl;
    }

    cout << sysconf(_SC_V6_ILP32_OFF32) << endl;
    cout << sysconf(_SC_V6_ILP32_OFFBIG) << endl;
    cout << sysconf(_SC_V6_LP64_OFF64) << endl;
    cout << sysconf(_SC_V6_LPBIG_OFFBIG) << endl;

    return 1;
}