#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "abc";
	char s2[] = "abcd";
	/* strcat(s1, s2); */
	char *p = strchr(s1, 'b');
	p = strchr(p+1, 'b');
	printf("%s\n", p);
	
	return 0;
	   
}
