#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char s1[6] = "Hello";
	char s2[6] = "World";	
	
	int i = 33;
	printf("%c", *(s1 + i));
	
}
