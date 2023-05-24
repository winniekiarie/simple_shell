#include "main.h"



/**
*execute - execute a command
*@fullPath: full path of the command
*@command: command to be executed
*Return: the status of the command execution
*/
int execute(char *fullPath, char **command)

{
pid_t child;
int status = 0;
struct stat st;
int i;

child = fork();
if (child == 0)
{
for (i = 0; i < 1; i++)
{
if (stat(fullPath, &st) == 0)
{
status = execve(fullPath, command, environ);
exit(status);
}
}
}
else
wait(NULL);
return (status);
}

