#include "main.h"

/**
* env - Print the current environment variables
* @env: A pointer to a char array containing the environment variables
*
* Return: 0 success.
*/

void env(char **env)
{
int i;

for (i = 0; env[i]; i++)
{
write(1, env[i], _strlen(env[i]));
write(1, "\n", 1);
}
return;
}

