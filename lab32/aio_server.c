#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <aio.h>
#include <errno.h>


char *socket_path = "./socket";

void mkcl(int const sock, struct aiocb **reqs, int const ind, char *buf, int const buf_size);

int main() {
    int listener;
    struct sockaddr_un addr;
    char *buf_1 = (char*)calloc(1024, sizeof(char));
    char *buf_2= (char*)calloc(1024, sizeof(char));

    listener = socket(AF_UNIX, SOCK_STREAM, 0);
    if (listener < 0) {
        perror("socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    if (*socket_path == '\0') {
        *addr.sun_path = '\0';
        strncpy(addr.sun_path + 1, socket_path + 1, sizeof(addr.sun_path) - 2);
    } else {
        strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);
        unlink(socket_path);
    }
    if (bind(listener, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("bind error");
        exit(-1);
    }

    if (listen(listener, 5) == -1) {
        perror("listen error");
        exit(-1);
    }

    struct aiocb **reqs = (struct aiocb**)calloc(2, sizeof(struct aiocb*));
    int nreq = 0;
    int sock;
    if ((sock = accept(listener, NULL, NULL)) < 0) {
        if (sock < 0) {
            perror("accept");
            exit(3);
        }
    }
    mkcl(sock, reqs, nreq++, buf_1, 1024);
    printf("First client connected!\n");
    if ((sock = accept(listener, NULL, NULL)) < 0) {
        if (sock < 0) {
            perror("accept");
            exit(3);
        }
    }
    mkcl(sock, reqs, nreq++, buf_2, 1024);
    printf("Second client connected!\n");
    while (1) {
        // Создаем запрос на чтение
        for (int i = 0; i < nreq; ++i) {
            aio_read(reqs[i]);
        }
        // Ждём события в одном из сокетов
        aio_suspend(reqs, nreq, NULL);

        // Получаем сообщение из сокета
        for (int i = 0; i < nreq; ++i) {
            if (aio_error(reqs[i]) == 0) {
                printf("User %d send message!\n", i);
                int err = aio_error(reqs[i]);
                int bytes_read = aio_return(reqs[i]);
                if (err != 0) {
                    perror("Error at aio_error()");
                    close(reqs[i]->aio_fildes);
                    exit(2);
                }
                // Поступили данные от клиента, читаем их

                if (bytes_read <= 0) {
                    // Соединение разорвано, удаляем сокет из множества
                    close(reqs[i]->aio_fildes);
                    --nreq;
                    continue;
                }
                for (int j = 0; j < bytes_read; ++j) {
                    char upChar = (char) toupper(((char*)reqs[i]->aio_buf)[j]);
                    write(STDOUT_FILENO, &upChar, sizeof(char));
                }
            }
        }
    }

    return 0;
}

void mkcl(int const sock, struct aiocb **reqs, int const ind, char *buf, int const buf_size) {
    reqs[ind] = (struct aiocb*)calloc(1, sizeof(struct aiocb));
    reqs[ind]->aio_fildes = sock;
    reqs[ind]->aio_buf = buf;
    reqs[ind]->aio_nbytes = buf_size;
}
