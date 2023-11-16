#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

void display_prompt(void) {
    printf(":) ");
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
