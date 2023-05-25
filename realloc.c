#include "shell.h"

/**
 * _custom_memset - Fills memory with a constant byte
 * @s: Pointer to the memory area
 * @b: The byte to fill the memory area with
 * @n: The number of bytes to be filled
 *
 * Return: A pointer to the memory area 's'
 */
char *_custom_memset(char *s, char b, unsigned int n)
{
        unsigned int i;

        for (i = 0; i < n; i++)
                s[i] = b;
        return s;
}

/**
 * free_string_array - Frees an array of strings
 * @str_array: Array of strings
 */
void free_string_array(char **str_array)
{
        char **temp = str_array;

        if (!str_array)
                return;
        while (*str_array)
                free(*str_array++);
        free(temp);
}

/**
 * _custom_realloc - Reallocates a block of memory
 * @ptr: Pointer to the previous block of memory
 * @old_size: Size of the previous block in bytes
 * @new_size: Size of the new block in bytes
 *
 * Return: Pointer to the reallocated block of memory
 */
void *_custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        char *p;

        if (!ptr)
                return malloc(new_size);
        if (!new_size)
                return (free(ptr), NULL);
        if (new_size == old_size)
                return ptr;

        p = malloc(new_size);
        if (!p)
                return NULL;

        old_size = old_size < new_size ? old_size : new_size;
        while (old_size--)
                p[old_size] = ((char *)ptr)[old_size];
        free(ptr);
        return p;
}
