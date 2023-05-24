#include "main.h"

/**
*exit_sh - exits the shell
*@command: array of command arguments
*Return: always returns 0
*Description: This function takes an array of command arguments and exits the
*shell. It frees all allocated memory and closes any open file streams. The
*return value is always 0 as this function never fails to exit the shell.
*It follows the standard format for a shell built-in function with a single
*argument that is not used in this case.
*/
int exit_sh(char **command)
{
if (*command)
{
buffers1(NULL, NULL);
buffers2(NULL, NULL);
buffers3(NULL, NULL);
buffers4(NULL, NULL);
buffers5(NULL);
exit(2);
}
return (0);
}

/**
*cd - changes the current directory
*@command: array of command arguments
*Return: 0 on success, -1 on error
*/
int cd(char **command)
{
chdir(command[1]);
return (0);
}
/**
*printenv - prints the environment
*@command: pointer to an array of strings containing command arguments
*Return: Always returns 0.
*/
int printenv(char **command)
{
int i;

if (*command)
{
i = 0;
while (environ[i])
{
write(1, environ[i], _strlen(environ[i]));
write(1, "\n", 1);
i++;
}
}
return (0);
}
/**
*checkBuiltins - checks if a command is a builtin
*@combine: command with arguments
*@command: array of arguments
*Return: 0 if the command is not a builtin, otherwise the return value
*of the corresponding builtin function
*/
int checkBuiltins(char *combine, char **command)
{
int i;
char *array[] = {"exit", "cd", "env", NULL};
typedef int (*Builtins)(char **);
Builtins functions[] = {&exit_sh, &cd, &printenv};

for (i = 0; array[i] != NULL; i++)
{
if (_strcmp(array[i], command[0]) == 0)
return (functions[i](command));
}
return (execute(combine, command));
}

