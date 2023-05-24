#include "main.h"

/**
*prompt - Prints the prompt for the shell.
*Return: Nothing.
*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
}
