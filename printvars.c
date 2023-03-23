#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *custom_env[] = {"USER=Pikachu", "PATH=/tmp", NULL};

int main(void)
{
    // TODO

    // fork two child processes
    // TODO: PARENT BEFORE CHILD1 BEFORE 
    printf("Running parent process PID: %d\n\n", getpid());

    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == 0) {
        // Child 1
        printf("Running child process PID: %d\n", getpid());
        const char* file = "/home/wyatt/bin/echoall";
        const char* band = "Bandicoot";
        const char* pac = "Pacman";
        execle(file, file, band, pac, NULL, custom_env);
        exit(0);
        
    }

    int status; 
    
    wait(&status);

    pid2 = fork();

    if (pid2 == 0) {
        //Child 2
        printf("Running child process PID: %d\n", getpid());
        const char* file = "echoall";
        const char* spyro = "Spyro";
        execlp(file, file, spyro, NULL);
        exit(0);
    }
    

}