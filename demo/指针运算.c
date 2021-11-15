#include <stdio.h> 

int main() {
	char ac[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
	char *p = ac;
	char *p1 = &ac[5]; 
	printf("p=%p\n", p);
	printf("p+1=%p\n", p+1);
	printf("p1-p=%d\n", p1-p);
	printf("*(p+1)=%d\n", *(p+1));
	int ai[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
	int *q = ai;
	int *q1 = &ai[6];
	printf("q=%p\n", q);
	printf("q1=%p\n", q1);
	printf("q1-q=%d\n", q1-q);
	return 0;
}
