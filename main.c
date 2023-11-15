#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void) {
    char *command;

    while (1) {
        display_prompt(); // Display the shell prompt
        command = read_command(); // Read user input

        if (command == NULL) {
            printf("\n");
            break; // Handle end of file condition (Ctrl+D)
        }

        execute_command(command); // Execute the command

        free(command); // Free allocated memory for command
    }

    handle_exit(); // Handle the exit built-in command

    return EXIT_SUCCESS;
}
