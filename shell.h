#ifndef SHELL_H
#define SHELL_H

#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
/* Constants */
#define BUFFER_SIZE 1024

/* Function prototypes */
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void handle_exit(void);
void handle_env(void);
void error_handler(char *msg);

#endif /* SHELL_H */
