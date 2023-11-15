#include "shell.h"

int main(void)
{
    char *command;

    while (1)
    {
        display_prompt();
        command = read_command();

        if (command == NULL)
        {
            printf("\n");
            break;
        }

        execute_command(command);
        free(command);
    }

    handle_exit();
    return EXIT_SUCCESS;
}
