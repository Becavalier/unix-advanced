#include "apue.h"
#include <dirent.h>
#include <iostream>

int main(int argc, char **argv) {

    /**
        typedef struct {
            int	__dd_fd;	
            long	__dd_loc;	
            long	__dd_size;
            char	*__dd_buf;
            int	__dd_len;
            long	__dd_seek;
            __unused long	__padding; 
            int	__dd_flags;	
            __darwin_pthread_mutex_t __dd_lock;
            struct _telldir *__dd_td;
        } DIR;
    */
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        return 1;
    }

    if ((dp = opendir(argv[1])) == NULL) {
        std::cerr << "[ls] can't open: " << argv[1] << std::endl;
    }

    while ((dirp = readdir(dp)) != NULL) {
        std::cout << dirp->d_name << std::endl;
    }
    closedir(dp);

    return 0;
}