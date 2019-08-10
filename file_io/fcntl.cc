#include <iostream>
#include "apue.h"
#include <fcntl.h>

using namespace std;

int main(int argc, char **argv) {
    int fd = open("./fcntl.cc", O_RDONLY | O_APPEND);

    int fd_dup = fcntl(fd, F_DUPFD);
    cout << fd_dup << endl;

    int fd_dup_cus = fcntl(fd, F_DUPFD, 1000);
    cout << fd_dup_cus << endl;

    int val = fcntl(fd, F_GETFL, 0);
    if (val >= 0) {
        // for "O_RDONLY", "O_RDWR", "O_WRONLY", "O_EXEC", "O_SEARCH";
        // Because "O_RDONLY" equals to 0x000;
        switch (val & O_ACCMODE) {
        case O_RDONLY:
            cout << "Read only!" << endl;
            break;
        default:
            break;
        }
    }

    cout << val << endl;
    if (val & O_APPEND) {
        cout << "Append mode!" << endl;
    }

#if defined(O_SYNC)

    if (fcntl(fd, F_SETFL, O_SYNC) >= 0) {
        // refresh flag value;
        val = fcntl(fd, F_GETFL);
        if (val & O_SYNC) {
            cout << "Sync mode!" << endl;
        }
    }

#endif

/*
    _POSIX_C_SOURCE == 1               1003.1-1990
    _POSIX_C_SOURCE == 2               1003.2-1992 C Language Binding Option
    _POSIX_C_SOURCE == 199309          1003.1b-1993
    _POSIX_C_SOURCE == 199506          1003.1c-1995, 1003.1i-1995,
    _POSIX_C_SOURCE == 200112          1003.1-2001
    _POSIX_C_SOURCE == 200809          1003.1-2008

 */
#if defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE > 199309L && defined(O_FSYNC) && O_FSYNC != O_SYNC
    // O_FSYNC == O_SYNC, wait writing (data and meta) process complete;
    if (val & O_FSYNC) {
        cout << "FSync mode!" << endl;
    }

#endif

    return 1;
}
