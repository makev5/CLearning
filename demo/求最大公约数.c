#include <stdio.h>
/* ���b=0�����������a�������Լ��
���򣬼���a / b ����������a = b����b = �Ǹ�������
�ص���һ����

�㷨:շת����� 
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
