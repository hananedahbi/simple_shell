#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// ... (other function implementations)

int handle_env_builtin(char *command) {
    if (strcmp(command, "env") == 0) {
        char **env = environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        }
        return 1;
    }
    return 0;
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

        if (handle_exit_builtin(args[0])) {
            free(input);
            free(args);
            break;
        }

        if (handle_env_builtin(args[0])) {
            free(input);
            free(args);
            continue;
        }

        char *full_command = find_command(args[0]);
        if (full_command != NULL) {
            execute_command(full_command, args);
            free(full_command);
        } else {
            fprintf(stderr, "./shell: %s: command not found\n", args[0]);
        }

        free(input);
        free(args);
    }

    handle_exit();
    return EXIT_SUCCESS;
}
