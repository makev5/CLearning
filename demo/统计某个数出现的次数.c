#include <stdio.h> 
/*
  写一个程序，输入数量不确定的[0,9]范围
  内的整数，统计每一种数字出现的次数，
  输入-1表示结束 
*/
int main() 
{	const int NUM = 10; 
	int count[10];
	int i;
	int x;
	for(i=0; i<NUM; i++) {
		count[i] = 0;
	}
	while(x != -1) {
		scanf("%d", &x);
		if (x>=0 && x<=9) {
			count[x]++;
		}
	}
	for(i=0;  i<10; i++) {
		printf("%d:%d\n", i, count[i]);
	}	
}
