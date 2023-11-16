#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void display_prompt(void) {
    printf("#cisfun$ ");
}

char *read_command(void) {
    char *command = NULL;
    size_t bufsize = 0;

    if (getline(&command, &bufsize, stdin) == -1) {
        free(command);
        return NULL; // Handle end of file condition (Ctrl+D)
    }

    return command;
}

void execute_command(char *command) {
    if (command != NULL && command[0] != '\n') {
        command[strlen(command) - 1] = '\0'; // Remove newline character

        if (access(command, X_OK) == 0) {
            pid_t child_pid = fork();

            if (child_pid == 0) {
                char *args[] = {command, NULL};
                execve(command, args, NULL);
                perror(command); // Execve failed
                exit(EXIT_FAILURE);
            } else if (child_pid < 0) {
                perror("Fork failed");
            } else {
                wait(NULL);
            }
        } else {
            fprintf(stderr, "./shell: %s: command not found\n", command);
        }
    }
}

void handle_exit(void) {
    printf("./shell: exit\n");
}

int main(void) {
    char *command;

    while (1) {
        display_prompt();
        command = read_command();

        if (command == NULL) {
            printf("\n");
            break; // Handle end of file condition (Ctrl+D)
        }

        execute_command(command);
        free(command);
    }

    handle_exit();
    return EXIT_SUCCESS;
}
