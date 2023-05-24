#include "main.h"

/**
*get_line - Reads an entire line from stdin
*Return: The line read from stdin
*/
char *get_line(void)
{
char *buf = NULL;
size_t bufsize = 0;
int test;

test = getline(&buf, &bufsize, stdin);
buffers3(NULL, buf);

if (test == EOF)
{
buffers1(NULL, NULL);
buffers2(NULL, NULL);
buffers3(NULL, NULL);
buffers4(NULL, NULL);
buffers5(NULL);
_exit(0);
}
return (buf);
}


/**
*split_line - split a line into an array of strings
*@line: a string of input to be split
*Return: an array of pointers to strings
*/
char **split_line(char *line)
{
char *dup_buf;
char *token;
char *toks;
char **tok;
int i;

dup_buf = _strdup(line);
token = strtok(line, DELIM);
for (i = 1; token; i++)
{
token = strtok(NULL, DELIM);
}

tok = malloc(sizeof(char *) * (i + 1));
buffers4(tok, NULL);

toks = strtok(dup_buf, DELIM);
for (i = 0; toks; i++)
{
tok[i] = toks;
toks = strtok(NULL, DELIM);
}
tok[i] = '\0';
return (tok);
}
