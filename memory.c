#include "shell.h"

/**
 * bfree - Frees a pointer and sets it to NULL.
 * @ptr: Address of the pointer to be freed.
 *
 * This function frees the memory allocated for the pointer and sets the pointer
 * to NULL. It helps to avoid memory leaks and ensures that the pointer is not
 * used after being freed.
 *
 * Return: 1 if the pointer is freed, or 0 if the pointer is NULL.
 */
int bfree(void **ptr)
{
        if (ptr && *ptr)
        {
                free(*ptr);
                *ptr = NULL;
                return 1;
        }
        return 0;
}
