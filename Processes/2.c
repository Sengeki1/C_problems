#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void P2P3();
void P4();

int main() {
    P2P3();
}

void P2P3() {
    pid_t p2 = fork();
    if (p2 == 0) {
        printf("P2 - PID = %d, PID-PAI = %d", getpid(), getppid());
        P4();
        wait(NULL);
        exit(0);
    } else {
        pid_t p3 = fork();
        if (p3 == 0) {
            printf("P3 - PID = %d, PID-PAI = %d", getpid(), getppid());
            sleep(2);
            exit(0);
        } else {
            printf("P1 - PID = %d", getpid());
            wait(NULL); // Aguardar P2 terminar
            wait(NULL); // Aguardar P3 terminar
        }
    }
}

void P4() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("P4 - PID = %d, PID-PAI = %d", getpid(), getppid());
        exit(0);
    }
}