#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>


char *socket_path = "./socket";

int main() {
    int listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }

    fcntl(listener, F_SETFL, O_NONBLOCK);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 2);
    int *clients = (int *) calloc(20, sizeof(int));
    int ncl = 0;
    while (1) {
        // Заполняем множество сокетов
        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(listener, &readset);

        for (int i = 0; i < ncl; i++) {
            FD_SET(clients[i], &readset);
        }

        // Задаём таймаут
        struct timeval timeout;
        timeout.tv_sec = 15;
        timeout.tv_usec = 0;

        // Ждём события в одном из сокетов
        int cl_mx = clients[0];
        for (int i = 0; i < ncl; ++i) {
            cl_mx = clients[i] > cl_mx ? clients[i] : cl_mx;
        }
        int mx = listener > cl_mx ? listener : cl_mx;
        if (select(mx + 1, &readset, NULL, NULL, &timeout) <= 0) {
            perror("select");
            exit(3);
        }

        // Определяем тип события и выполняем соответствующие действия
        if (FD_ISSET(listener, &readset)) {
            // Поступил новый запрос на соединение, используем accept
            int sock = accept(listener, NULL, NULL);
            if (sock < 0) {
                perror("accept");
                exit(3);
            }

            fcntl(sock, F_SETFL, O_NONBLOCK);
            clients[ncl++] = sock;
        }

        for (int i = 0; i < ncl; ++i) {
            if (FD_ISSET(clients[i], &readset)) {
                // Поступили данные от клиента, читаем их
                bytes_read = recv(clients[i], buf, 1024, 0);

                if (bytes_read <= 0) {
                    // Соединение разорвано, удаляем сокет из множества
                    close(clients[i]);
                    --ncl;
                    continue;
                }
                for (int j = 0; j < bytes_read; ++j) {
                    char upChar = (char) toupper(buf[j]);
                    write(STDOUT_FILENO, &upChar, sizeof(char));
                }
            }
        }
    }

    return 0;
}