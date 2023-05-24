#include "main.h"
/**
* loop - function to get user input, tokenize directory and
* check for builtins. Main loop to initiate shell
* @env: A double pointer to an array of environment variables.
* Return: void
*/
void loop(char **env)
{
char *line;
char **dir, **command;
char *combine;

while (1)
{
prompt();
signal(SIGINT, handler);
line = get_line();

command = split_line(line);
dir = dirTok(env);
combine = checkPath(dir, command[0]);
checkBuiltins(combine, command);
if (!combine)
perror(combine);
}
buffers1(NULL, NULL);
buffers2(NULL, NULL);
buffers3(NULL, NULL);
buffers4(NULL, NULL);
buffers5(NULL);
}
