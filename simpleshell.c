#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void execute_command(char *command) {
    // Tokenize the command
    char *args[MAX_ARGUMENTS];
    char *token = strtok(command, " ");
    int i = 0;
    while (token != NULL && i < MAX_ARGUMENTS - 1) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;

    // Execute the command
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        // execvp only returns if an error occurs
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Fork failed
        perror("fork");
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        // Print shell prompt
        printf("$ ");

        // Read command from user
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            break; // Exit on EOF or error
        }

        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command by semicolon to handle multiple commands
        char *token = strtok(command, ";");
        while (token != NULL) {
            // Execute each command
            execute_command(token);
            token = strtok(NULL, ";");
        }
    }

    return 0;
}
