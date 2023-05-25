#include "shell.h"

/**
 * my_strncpy - Copies a string
 * @dest: The destination string to be copied to
 * @src: The source string
 * @n: The maximum number of characters to be copied
 *
 * Return: A pointer to the destination string
 */
char *my_strncpy(char *dest, const char *src, int n)
{
        int i, j;
        char *result = dest;

        i = 0;
        while (src[i] != '\0' && i < n - 1)
        {
                dest[i] = src[i];
                i++;
        }
        if (i < n)
        {
                j = i;
                while (j < n)
                {
                        dest[j] = '\0';
                        j++;
                }
        }
        return result;
}

/**
 * my_strncat - Concatenates two strings
 * @dest: The first string
 * @src: The second string
 * @n: The maximum number of bytes to be used
 *
 * Return: A pointer to the concatenated string
 */
char *my_strncat(char *dest, const char *src, int n)
{
        int i, j;
        char *result = dest;

        i = 0;
        j = 0;
        while (dest[i] != '\0')
                i++;
        while (src[j] != '\0' && j < n)
        {
                dest[i] = src[j];
                i++;
                j++;
        }
        if (j < n)
                dest[i] = '\0';
        return result;
}

/**
 * my_strchr - Locates a character in a string
 * @s: The string to be searched
 * @c: The character to look for
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *my_strchr(const char *s, char c)
{
        while (*s != '\0')
        {
                if (*s == c)
                        return (char *)s;
                s++;
        }
        return NULL;
}
