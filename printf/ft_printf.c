#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


// Forbidden
#include <stdio.h>


static int	count_digits(long n)
{
	int	digits;

	digits = (n < 0);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*case_zero(void)
{
	char	*res;

	res = malloc(2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static char	*ft_itoa(int n)
{
	int			digits;
	long		positive_n;
	char		*res;

	if (n == 0)
		return (case_zero());
	digits = count_digits(n);
	res = malloc(digits + 1);
	if (!res)
		return (NULL);
	positive_n = (long)n;
	if (n < 0)
	{
		positive_n = -(long)n;
		res[0] = '-';
	}
	res[digits] = '\0';
	while (digits - 1 >= (n < 0))
	{
		res[digits - 1] = (positive_n % 10) + '0';
		positive_n /= 10;
		digits--;
	}
	return (res);
}

// malloc, free, write, va_start, va_arg, va_copy, va_end
//
int ft_printf(const char *format, ...)
{
    va_list args;

    int int_buffer;
    char char_buffer;
    char temp;
    int i;
    int counter;
    char *array_char_buffer;

	counter = 0;
    i = 0;
    va_start(args, format);

    while(format[i] != '\0')
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            i++;
            counter++;
            continue ;
        }

        if (format[i + 1] == 'd' || format[i + 1] == 'i')
        {
            int_buffer = va_arg(args, int);
            array_char_buffer = ft_itoa(int_buffer);
            write(1, array_char_buffer, 2);
            i++; // Skip d
        }

        if (format[i + 1] == 'c')
        {
            char_buffer = va_arg(args, int);
            write(1, &char_buffer, 1);

	    counter++;
            i++;
        }

        i++;
    }


    return (counter);

    va_end(args);
}

/*
int main()
{
    ft_printf   ("Hello %c %d\n", 'C', 42);
    printf      ("Hello %d\n", 42);
}
*/
