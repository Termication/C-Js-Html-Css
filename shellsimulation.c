#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];

    while (1) {
        printf("CustomShell> ");
        fflush(stdout);

        // Read the command from the user
        fgets(command, sizeof(command), stdin);

        // Remove trailing newline character
        command[strcspn(command, "\n")] = 0;

        // Tokenize the command
        char *token = strtok(command, " ");
        int arg_index = 0;
        while (token != NULL && arg_index < MAX_ARGUMENTS - 1) {
            arguments[arg_index++] = token;
            token = strtok(NULL, " ");
        }
        arguments[arg_index] = NULL; // Null-terminate the argument list

        // Handle built-in commands
        if (strcmp(arguments[0], "exit") == 0) {
            printf("Exiting CustomShell\n");
            break;
        } else if (strcmp(arguments[0], "cd") == 0) {
            if (chdir(arguments[1]) != 0) {
                perror("cd");
            }
            continue;
        }

        // Fork a child process to execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child process
            if (execvp(arguments[0], arguments) < 0) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else { // Parent process
            // Wait for the child process to terminate
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
