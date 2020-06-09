#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <signal.h>


int main(int argc, char *argv[]) {
    int const NFDS = argc-1;
    struct pollfd fds[NFDS];
    for (int i = 0; i < NFDS; ++i) {
        printf("%s\n", argv[i + 1]);
        if ((fds[i].fd = open(argv[i + 1], O_RDONLY)) == -1) {
            perror("Open error");
            exit(1);
        }
        fds[i].events = POLLIN;
    }
    int count;
    while (1) {
        count = poll(fds, NFDS, 5000);
        if (count == -1) {
            perror("poll failed");
            exit(1);
        }
        if (count == 0) {
            printf("No data for reading\n");
            exit(0);
        }
        for (int i = 0; i < NFDS; ++i) {
            if (fds[i].revents & POLLIN) {
                printf("There is data for reading fd %d\n", fds[i].fd);
                char out[BUFSIZ];
                int llen = read(fds[i].fd, out, BUFSIZ);
                out[llen] = '\0';
                printf("The data is: %s", out);
            }
        }
    }

    return 0;
}
