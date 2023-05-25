#include "shell.h"

/**
 * is_interactive_mode - Returns true if the shell is in interactive mode
 * @info: Struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive_mode(info_t *info)
{
        return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - Checks if a character is a delimiter
 * @c: The character to check
 * @delim: The delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char c, char *delim)
{
        while (*delim)
                if (*delim++ == c)
                        return (1);
        return (0);
}

/**
 * is_alpha - Checks for an alphabetic character
 * @c: The character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int is_alpha(int c)
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return (1);
        else
                return (0);
}

/**
 * string_to_integer - Converts a string to an integer
 * @s: The string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int string_to_integer(char *s)
{
        int i, sign = 1, flag = 0, output;
        unsigned int result = 0;

        for (i = 0; s[i] != '\0' && flag != 2; i++)
        {
                if (s[i] == '-')
                        sign *= -1;

                if (s[i] >= '0' && s[i] <= '9')
                {
                        flag = 1;
                        result *= 10;
                        result += (s[i] - '0');
                }
                else if (flag == 1)
                        flag = 2;
        }

        if (sign == -1)
                output = -result;
        else
                output = result;

        return (output);
}
