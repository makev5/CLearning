#include <stdio.h>
#include <math.h>
/* 
	水仙花数是指一个N位正整数（N>=3） ,它的每个位上的数字的N次幂之和等于本身。例如：153=13 + 53 33 
*/
int main(){
	int i;
	int cnt=0; 
	for(i=100; i < 1000; i++) {
		int bai = i / 100;
		int shi = i / 10 % 10;
		int ge = i % 10;
		if(i == pow(bai, 3) + pow(shi, 3) + pow(ge, 3)){
			printf("%d是水仙花数\n", i);
			cnt++;
		};
	}
	printf("共有水仙花数：%d", cnt);
	return 0;
} 
