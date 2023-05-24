#include "main.h"

/**
* pathCat - Concatenates the directory and user input to check for a builtin
* @dir: A pointer to a char array containing the directory
* @input: A pointer to a char array containing user input
*
* Return: A pointer to a char array containing the
* concatenation of dir and input
*/
char *pathCat(char *dir, char *input)
{
int i, k, len1, len2;
char *buf;

len1 = _strlen(dir);
len2 = _strlen(input);

buf = malloc(4096);
buffers4(NULL, buf);

for (i = 0; i < len1; i++)
{
buf[i] = dir[i];
}

for (k = 0; k < len2; k++, i++)
{
buf[i] = input[k];
}

buf[i] = '\0';
return (buf);
}


/**
* get_env - gets env in order to navigate PATH
* @env: double pointer
* Return: buf
*/
char *get_env(char **env)
{
int i, k;
char *start, *buf, *str = "PATH=";

i = 0;
while (env[i])
{
k = 0;
while (env[i][k] == str[k])
{
if (env[i][k + 1] == str[k + 1])
{
start = env[i];
break;
}
k++;
}
i++;
}
_strlen(start);
buf = malloc(4096);
buffers3(NULL, buf);
i = 0;
k = 0;
while (start[i] != '\0')
{
if (start[i] == ':')
{
buf[k] = '/';
k++;
}
buf[k] = start[i];
i++;
k++;
}
buf[k] = '/';
k++;
buf[k] = '\0';
return (buf);
}
/**
* dirTok - split directories to tokens
* @env: double pointer
* Return: tokens
*/
char **dirTok(char **env)
{
char **tokens;
char *tok;
int i, j;
char *dir;

dir = get_env(env);
i = 0;
j = 0;
while (env[j])
j++;
tokens = malloc(4096);
buffers3(tokens, NULL);

tok = strtok(dir, " :");
while (tok != NULL)
{
tokens[i] = tok;
i++;
tok = strtok(NULL, " :");
}
tokens[i] = NULL;
return (tokens);
}

/**
* checkPath - checks command input against path
* @dir: dirctory tokens
* @command: command line input
* Return: full path on success
*/
char *checkPath(char **dir, char *command)
{
struct stat st;
char *fullPath;

if (command[0] == '/')
return (command);

while (*dir)
{
fullPath = pathCat(*dir, command);
if (stat(fullPath, &st) == 0)
return (fullPath);
dir++;
}
return (NULL);
}

