#include "shell.h"

/**
 * erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int erratoi(char *s)
{
        int i = 0;
        unsigned long int result = 0;

        if (*s == '+')
                s++;  /* TODO: why does this make main return 255? */
        for (i = 0; s[i] != '\0'; i++)
        {
                if (s[i] >= '0' && s[i] <= '9')
                {
                        result *= 10;
                        result += (s[i] - '0');
                        if (result > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (result);
}

/**
 * print_error_msg - prints an error message
 * @info: the parameter & return info struct
 * @error_msg: string containing specified error type
 * Return: void
 */
void print_error_msg(info_t *info, char *error_msg)
{
        _eputs(info->fname);
        _eputs(": ");
        print_line_number(info->line_count, STDERR_FILENO);
        _eputs(": ");
        _eputs(info->argv[0]);
        _eputs(": ");
        _eputs(error_msg);
}

/**
 * print_line_number - prints the line number
 * @line_number: the line number
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_line_number(int line_number, int fd)
{
        int (*_putchar)(char) = _putchar;
        int i, count = 0;
        unsigned int abs_val, current;

        if (fd == STDERR_FILENO)
                _putchar = _eputchar;
        if (line_number < 0)
        {
                abs_val = -line_number;
                _putchar('-');
                count++;
        }
        else
                abs_val = line_number;
        current = abs_val;
        for (i = 1000000000; i > 1; i /= 10)
        {
                if (abs_val / i)
                {
                        _putchar('0' + current / i);
                        count++;
                }
                current %= i;
        }
        _putchar('0' + current);
        count++;

        return (count);
}

/**
 * convert_number - converts a number to a string
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
        static char *array;
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long n = num;

        if (!(flags & CONVERT_UNSIGNED) && num < 0)
        {
                n = -num;
                sign = '-';
        }
        array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
        ptr = &buffer[49];
        *ptr = '\0';

        do
        {
                *--ptr = array[n % base];
                n /= base;
        } while (n != 0);

        if (sign)
                *--ptr = sign;
        return (ptr);
}

/**
 * remove_comments - replaces the first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: void
 */
void remove_comments(char *buf)
{
        int i;

        for (i = 0; buf[i] != '\0'; i++)
        {
                if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
                {
                        buf[i] = '\0';
                        break;
                }
        }
}
