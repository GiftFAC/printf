#include "main.h"
#include <ctype.h> // Include for is_digit function

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Current position in the format string
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return precision;

    precision = 0;

    for (curr_i++; format[curr_i] != '\0'; curr_i++)
    {
        if (isdigit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
        {
            // Handle unexpected character (print an error or break gracefully)
            break;
        }
    }

    *i = curr_i - 1;

    return precision;
}
