#include <iostream>
#include <errno.h>
#include "apue.h"


int main(int argc, char **argv) { 
    // char	*strerror(int __errnum) __DARWIN_ALIAS(strerror);
    fprintf(stderr, "EACESS: %s\n", strerror(EACCES));

    errno = ENOENT;
    // void perror(const char *);
    perror(argv[0]);

    return 1;
}