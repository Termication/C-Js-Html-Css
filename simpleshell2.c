#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFSIZE 1024 
#define DELIMS " \t\r\n\a" 

/**
 * read_line - Reads a line of input from the user.
 * Return: The line of input, or NULL on error or end of file.
 */
char *read_line(void)
{
    int bufsize = BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "simple_shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        /* Check for end of file (Ctrl-D) or newline */
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer; 
        } else {
            buffer[position] = c;
        }
        position++;

        /* Reallocate buffer if it's too small */
        if (position >= bufsize) {
            bufsize += BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "simple_shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

/**
 * split_line - Splits the command line into an array of tokens.
 * @line: The command line to split.
 * Return: An array of tokens, or NULL on error.
 */
char **split_line(char *line)
{
    int bufsize = BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        fprintf(stderr, "simple_shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIMS);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "simple_shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIMS);
    }
    tokens[position] = NULL;
    return tokens;
}

/**
 * execute - Executes the given command.
 * @args: An array of tokens representing the command and its arguments.
 * Return: 0 on success, or -1 on error.
 */
int execute(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("simple_shell");
        }
        exit(EXIT_FAILURE); 
    } else if (pid < 0) {
        /* Error forking */
        perror("simple_shell");
    } else {
        /* Parent process */
        waitpid(pid, &status, 0);
    }

    return 0;
}

/**
 * main - Entry point of the shell.
 * Return: Always returns 0.
 */
int main(void)
{
    char *line;
    char **args;

    while (1) {
        printf("$ ");
        line = read_line();
        if (line == NULL) { /* Handle Ctrl-D */
            printf("\n"); 
            break;
        }
        args = split_line(line);
        execute(args);  

        free(line); 
        free(args);
    }

    return 0;
}
