#include <stdio.h> 
/*
  дһ����������������ȷ����[0,9]��Χ
  �ڵ�������ͳ��ÿһ�����ֳ��ֵĴ�����
  ����-1��ʾ���� 
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
