#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void display_prompt(void) {
    printf("#cisfun$ ");
}

char **parse_input(char *input) {
    char **args = malloc(BUFFER_SIZE * sizeof(char *));
    if (args == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    char *token;
    int index = 0;

    token = strtok(input, " \t\n\r\a");
    while (token != NULL) {
        args[index++] = token;
        token = strtok(NULL, " \t\n\r\a");
    }
    args[index] = NULL;

    return args;
}

void execute_command(char **args) {
    if (args[0] != NULL) {
        if (access(args[0], X_OK) == 0) {
            pid_t child_pid = fork();

            if (child_pid == 0) {
                execve(args[0], args, NULL);
                perror(args[0]); // Execve failed
                exit(EXIT_FAILURE);
            } else if (child_pid < 0) {
                perror("Fork failed");
            } else {
                wait(NULL);
            }
        } else {
            fprintf(stderr, "./shell: %s: command not found\n", args[0]);
        }
    }
}

int main(void) {
    char *input;
    char **args;

    while (1) {
        display_prompt();
        input = read_command();

        if (input == NULL) {
            printf("\n");
            break; // Handle end of file condition (Ctrl+D)
        }

        args = parse_input(input);
        execute_command(args);

        free(input);
        free(args);
    }

    handle_exit();
    return EXIT_SUCCESS;
}
