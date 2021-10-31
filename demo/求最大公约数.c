#include <stdio.h>
/* 如果b=0，计算结束，a就是最大公约数
否则，计算a / b 的余数，让a = b，而b = 那个余数；
回到第一步。

算法:辗转相除法 
a	b	t
12	18	12
18	12	6
12	6	0
6	0
*/
int main(){
	int a,b;
	int t;
	scanf("%d, %d", &a, &b);
	a = 12;b = 18;
	while(b != 0){
		t = a % b;
		a = b;
		b = t;
		printf("a=%d, b=%d, t=%d\n",a ,b, t);
	}
	printf("gcd=%d\n", a);
	return 0;
} 
