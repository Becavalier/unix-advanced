#include <iostream>
#include "apue.h"
#include <errno.h>
#include <limits.h>

using namespace std;

// function test macro;
#define _POSIX_C_SOURCE 200809l

// 1. limits.h -> static constant;
#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif

static long posixVersion = 0;
static long xsiVersion = 0;

#define PATH_MAX_GUESS 1024

char* path_alloc(size_t *sizep) {
    char *ptr;
    size_t size;

    if (posixVersion == 0) {
        posixVersion = sysconf(_SC_VERSION);
    }
    
    if (xsiVersion == 0) {
        xsiVersion = sysconf(_SC_XOPEN_VERSION);
    }

    if (pathmax == 0) {
        errno = 0;
        // 2. pathconf -> dynamic magic number;
        if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
            if (errno == 0) {
                pathmax = PATH_MAX_GUESS;
            } else {
                perror("error: ");
            }
        } else {
            // including "/";
            pathmax += 1;
        }
    }

    // 3. compatibility (no null symbol);
    if ((posixVersion < 200112L) && (xsiVersion < 4)) {
        // not comply the SUS standard;
        size = pathmax + 1;
    } else {
        size = pathmax;
    }

    if ((ptr = static_cast<char*>(malloc(size))) == nullptr) {
        cerr << "system error!" << endl;
    }

    if (sizep != nullptr) {
        *sizep = size;
    }

    return ptr;
}

int main(int argc, char** argv) {
    size_t x = 0;
    auto headPtr = path_alloc(&x);
    
    cout << x << endl;
    return 1;
}