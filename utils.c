#include "shell.h"

/**
 * _strlen - calculates the length of a string
 * Description: This function returns the number of characters in
 * the string pointed to by s, excluding the terminating null byte.
 * @s: pointer to the input string
 *
 * Return: the length of the string, or 0 if s is NULL
 */

int _strlen(char *s)
{
	int len = 0;

	while (s && s[len])
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - copies a string to another buffer
 * Description: This function copies the string pointed to by src,
 * including the terminating null byte, into the buffer pointed to
 * by dest.
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (!dest || !src)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * Description: This function appends the string pointed to by src
 * to the end of the string pointed to by dest. The dest buffer must
 * have enough space to hold the result.
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	if (!dest || !src)
		return (dest);

	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
