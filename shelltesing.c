#include "main.h"

/**
 * display_prompt - Displays a prompt for the user to enter a command.
 */
void display_prompt() {
    printf("$ ");
}

/**
 * read_command - Reads a command line from the user.
 * 
 * Returns:
 *   - The command line entered by the user.
 *   - NULL if end of file (Ctrl+D) is encountered.
 */
char *read_command() {
    char *input = NULL;
    size_t bufsize = 0;
    ssize_t characters_read;

    printf("$ ");  // Display prompt

    // Read command line from user
    characters_read = getline(&input, &bufsize, stdin);

    if (characters_read == -1) {
        // End of file (Ctrl+D) encountered
        free(input);
        return NULL;
    }

    // Remove newline character from input
    if (input[characters_read - 1] == '\n') {
        input[characters_read - 1] = '\0';
    }

    return input;
}

/**
 * tokenize_command - Tokenizes the command line input by the user.
 * 
 * @command_line: The command line input by the user.
 * @args: Array to store the tokens.
 * 
 * Returns:
 *   - The number of tokens (including the command itself).
 */
int tokenize_command(char *command_line, char **args) {
    char *token;
    int i = 0;

    // Tokenize the command line
    token = strtok(command_line, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;  // Null-terminate the array

    return i;
}

/**
 * execute_command - Executes a command with its arguments.
 * 
 * @args: Array containing the command and its arguments.
 */
void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            // Error executing command
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

/**
 * main - Entry point of the shell program.
 */
int main() {
    char *command_line;
    char *args[MAX_ARGS];
    int num_args;

    while (1) {
        // Display prompt and read command line
        command_line = read_command();
        if (command_line == NULL) {
            // End of file (Ctrl+D) encountered
            printf("\n");
            break;
        }

        // Tokenize the command line
        num_args = tokenize_command(command_line, args);

        // Execute the command with its arguments
        execute_command(args);

        // Free memory allocated for command line
        free(command_line);
    }

    return 0;
}
