#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * size - gets the length of an array
 * @format: the text it recieves
 * Description: bla bla bla
 * Return: size of the array
 */

int size(const char *format)
{
        int n;

        for (n = 0; *format != '\0'; n++)
                format++;

        return (n);
}

/**
 * print_string - prints a string
 * @args: the list of arguments
 * Description: bla bla bla
 * Return: count
 */

int print_string(va_list args)
{
    char *value = va_arg(args, char *);
    int count = strlen(value);
    write(STDOUT_FILENO, value, strlen(value));
    return count;
}

/**
 * print_char - prints a character
 * @args: the list of arguments
 * Description: bla bla bla
 * Return: count
 */

int print_char(va_list args)
{
    int value = va_arg(args, int);
    write(STDOUT_FILENO, &value, 1);
    return 1;
}

/**
 * _printf - prints formated text
 * @format: the text it recieves
 * Description: bla bla bla
 * Return: 0
 */

int _printf(const char *format, ...)
{
    int n;
    int count = 0;
    va_list args;

    va_start(args, format);

    if (format == NULL)
        return (-1);

    for (n = 0; format[n] != '\0'; n++)
    {
        if (format[n] == '%' && format[n + 1] == 's')
        {
            count += print_string(args);
            n++;
        }
        else if (format[n] == '%' && format[n + 1] == 'c')
        {
            count += print_char(args);
            n++;
        }
        else if (format[n] == '%' && format[n + 1] == '%')
        {
            write(STDOUT_FILENO, "%", 1);
            count++;
            n++;
        }
        else
        {
            count++;
            write(STDOUT_FILENO, &format[n], 1);
        }
    }

    return (count);
}
