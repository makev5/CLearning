#include <stdio.h>
#include <math.h>
/* 
	ˮ�ɻ�����ָһ��Nλ��������N>=3�� ,����ÿ��λ�ϵ����ֵ�N����֮�͵��ڱ������磺153=13 + 53 33 
*/
int main(){
	int i;
	int cnt=0; 
	for(i=100; i < 1000; i++) {
		int bai = i / 100;
		int shi = i / 10 % 10;
		int ge = i % 10;
		if(i == pow(bai, 3) + pow(shi, 3) + pow(ge, 3)){
			printf("%d��ˮ�ɻ���\n", i);
			cnt++;
		};
	}
	printf("����ˮ�ɻ�����%d", cnt);
	return 0;
} 
