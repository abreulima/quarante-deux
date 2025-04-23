
#include <stdarg.h>
#include <stdio.h>

void variadic(const char *s, ...)
{
	va_list args;


	va_start(args, s);

	int test;
	
	while(*s)
		{

			if (*s == 'd')
			{
				test = va_arg(args, int);
				printf("%d", test);
			}

			else if (*s == 'c')
			{
				test = va_arg(args, int);
				printf("%c", test);
			}
			else 
			{
				printf("%c", *s);
			}

			s++;
		}
	
	va_end(args);

	

}

int main()
{

	variadic("%c %d", 42, 'C');
	
}
