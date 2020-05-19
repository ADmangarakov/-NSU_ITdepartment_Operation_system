
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#include "header.h"
#include "ctype.h"

int setNewAttr(int terminal, struct termios *old_option) {
    struct termios new_option;

    if (tcgetattr(terminal, old_option) == ERROR) {
        perror("Error tcgetattr");
        return EXIT_FAILURE;
    }

    new_option = *old_option;
    new_option.c_lflag &= ~(ICANON);
    new_option.c_cc[VMIN] = COUNT_SYMBS;
    new_option.c_cc[VTIME] = 0;

    if (tcsetattr(terminal, TCSANOW, &new_option) == ERROR) {
        perror("Error tcsetattr");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int setOldAttr(int terminal, struct termios *old_option) {
    if (tcsetattr(terminal, TCSANOW, old_option) == ERROR) {
        perror("Error tcsetattr");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int erase(int terminal, char *string, size_t *lengthString, char c) {
    if (*lengthString <= 0) {
        return EXIT_SUCCESS;
    }

    if(write(terminal, "\b \b", 3) == ERROR) {
        perror("Error write");
        return EXIT_FAILURE;
    }
    --(*lengthString);


    return EXIT_SUCCESS;
}

int eraseWord(int terminal, char *string, size_t *lengthString, char c) {
    while (isspace(string[(*lengthString) - 1]) && *lengthString > 0) {
        if(erase(terminal, string, lengthString, c) != EXIT_SUCCESS) {
            perror("Error write");
            return EXIT_FAILURE;
        }
    }

    while (!isspace(string[(*lengthString) - 1]) && *lengthString > 0) {
        if(erase(terminal, string, lengthString, c) != EXIT_SUCCESS) {
            perror("Error write");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int eraseString(int terminal, char *string, size_t *lengthString, char c) {
    while (*lengthString > 0) {
        if(write(terminal, "\b \b", 3) == ERROR) {
            perror("Error write");
            return EXIT_FAILURE;
        }
        --(*lengthString);
    }

    return EXIT_SUCCESS;
}

int validEmail(int terminal) {
    char buffer[COUNT_SYMBS] = {};
    char question[] = "Enter email: ";
    char answer[] = "\nYour symbol: ";
    char valid[] = "\nValid";
    char invalid[] = "\nInvalid";
    char newLine[] = "\n";
    char curMail[EMAIL_LEN] = "\0";
    if (write(terminal, question, strlen(question)) == ERROR) {
        perror("Error write");
        return EXIT_FAILURE;
    }

    int mailLen = 0;
    int validLast = 0;
    int withDog = 0;
    while (1) {
        if (write(terminal, curMail, strlen(curMail)) == ERROR) {
            perror("Error write");
            return EXIT_FAILURE;
        }

        if (read(terminal, buffer, COUNT_SYMBS) == ERROR) {
            perror("Error read");
            return EXIT_FAILURE;
        }
        if (newOption->c_cc[VERASE])
        curMail[mailLen] = buffer[0];
        ++mailLen;
        if (curMail[mailLen-1] == '@' || curMail[mailLen-1] == '.') {
            validLast = 0;
        }

        if (write(terminal, answer, strlen(answer)) == ERROR) {
            perror("Error write");
            return EXIT_FAILURE;
        }

        if (write(terminal, buffer, COUNT_SYMBS) == ERROR) {
            perror("Error write");
            return EXIT_FAILURE;
        }

        if (write(terminal, newLine, strlen(newLine)) == ERROR) {
            perror("Error write");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;

}

int getInput(int terminal) {
    char buffer[COUNT_SYMBS] = {};
    char question[] = "Enter symbol: ";
    char answer[] = "\nYour symbol: ";
    char newLine[] = "\n";

    if (write(terminal, question, strlen(question)) == ERROR) {
        perror("Error write");
        return EXIT_FAILURE;
    }

    if (read(terminal, buffer, COUNT_SYMBS) == ERROR) {
        perror("Error read");
        return EXIT_FAILURE;
    }

    if (write(terminal, answer, strlen(answer)) == ERROR) {
        perror("Error write");
        return EXIT_FAILURE;
    }

    if (write(terminal, buffer, COUNT_SYMBS) == ERROR) {
        perror("Error write");
        return EXIT_FAILURE;
    }

    if (write(terminal, newLine, strlen(newLine)) == ERROR) {
        perror("Error write");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main() {
    int terminal = open("/dev/tty", O_RDWR);
    if (terminal == ERROR) {
        perror("Error open terminal");
        return EXIT_FAILURE;
    }

    if(!isatty(terminal)) {
        perror("Open not terminal");
        close(terminal);
        return EXIT_FAILURE;
    }

    struct termios old_option;
    if(setNewAttr(terminal, &old_option) != EXIT_SUCCESS) {
        close(terminal);
        return EXIT_FAILURE;
    }

    if(getInput(terminal) != EXIT_SUCCESS) {
        setOldAttr(terminal, &old_option);
        close(terminal);
        return EXIT_FAILURE;
    }

    if(setOldAttr(terminal, &old_option) != EXIT_SUCCESS) {
        close(terminal);
        return EXIT_FAILURE;
    }

    close(terminal);
    return EXIT_SUCCESS;
}
