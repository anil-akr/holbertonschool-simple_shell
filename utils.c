#include "shell.h"

int _strlen(char *s)
{
    int len = 0;
    while (s && s[len])
        len++;
    return len;
}

char *_strcpy(char *dest, char *src)
{
    int i = 0;
    if (!dest || !src)
        return dest;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;
    if (!dest || !src)
        return dest;

    while (dest[i])
        i++;
    while (src[j])
        dest[i++] = src[j++];
    dest[i] = '\0';
    return dest;
}
