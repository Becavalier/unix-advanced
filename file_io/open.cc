#include "apue.h"
#include <fcntl.h>
#include <iostream>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <memory>

using namespace std;
using filestat = struct stat;

int main(int argc, char **argv) {
    int fd_1 = open("./open.cc", O_RDWR | O_CREAT | O_APPEND);

    // AT_FDCWD -> current working directory;
    int fd_2 = openat(AT_FDCWD, "open.cc", O_RDWR | O_CREAT | O_APPEND);

    // O_WRONLY and O_RDWR and not allowed for directories;
    auto fd_dir = open("./", O_RDONLY);
    int fd_3 = openat(fd_dir, "open.cc", O_RDWR | O_CREAT | O_APPEND);

    // retrive file stats;
    shared_ptr<filestat> buf(new filestat());
    fstat(5, buf.get());
    cout << buf->st_ino << endl;

    cout << fd_1 << ":" << fd_2 << ":" << fd_dir << ":" << fd_3 << endl;

    // the system will auto closing the opening file when program terminates;
    close(fd_1);
    close(fd_2);
    close(fd_dir);
    close(fd_3);

    return 0;
}