#include "main.h"

/**
*_strcmp - compares two strings
*@s1: first string
*@s2: second string
*Return: an integer less than, equal to, or greater than zero if s1 is found,
*respectively, to be less than, to match, or be greater than s2
*/
int _strcmp(char *s1, char *s2)
{
while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
{
s1++;
s2++;
}
if (*s1 == *s2)
{
return (0);
}
else
{
return (*s1 - *s2);
}
}

/**
*_strdup - returns a pointer to a newly allocated space in memory,
*which contains a copy of the string given as a parameter.
*@str: the string to duplicate
*Return: a pointer to the duplicated string, or NULL if insufficient memory
*is available.
*/
char *_strdup(char *str)
{
char *dup = NULL;
int i;
int k = 0;

if (str == NULL)
return (NULL);
while (str[k] != '\0')
k++;
dup = malloc(4096);
buffers5(dup);
if (dup == NULL)
return (NULL);
i = 0;
while (i <= k)
{
dup[i] = str[i];
i++;
}
return (dup);
}

/**
*_strlen - Returns the length of a string
*@s: Pointer to string
*Return: Length of the string
*/
int _strlen(char *s)
{
int i;

for (i = 0; s[i] != '\0'; i++)
;

return (i);
}
