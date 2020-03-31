#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main() {
    struct flock lock;
    char const * const FILE_NAME = "test.txt";
    int fd = open(FILE_NAME, O_RDWR);
    if (fd == -1){
        perror("Error while open file: ");
        exit(EXIT_FAILURE);
    }

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0; // whole file address space
    fcntl(fd, F_SETLK, &lock);
    if ((errno == EACCES) || (errno == EAGAIN)) {
        printf("%s busy -- try later\n", FILE_NAME);
        exit(2);
    }

    char command[32];
    snprintf(command, sizeof(char) * 32, "nano %s", FILE_NAME);
    system(command);

    lock.l_type = F_UNLCK; /* unlock file */
    fcntl(fd, F_SETLK, &lock);
    close(fd);

    return 0;
    // set mandatory mode "chmod +l filename"
    //
}
