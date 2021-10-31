#include <stdio.h>
#include <math.h>

/*
  ȥ��ż���󣬴�3��x-1��ÿ�μ�2 
*/
int isPrime(int x){
	int ret = 1;
	int i;
	if(x ==1 || (x%2 ==0 && x!=2)) ret =0;
	
	for(i=3; i<sqrt(x); i+=2){
		if(x % i == 0){
			ret = 0;
			break;
		}
	}
	return ret; 
}

int main(){
	int i;
	for(i=1; i<100; i++){
		printf("%d�Ƿ���������%d\n", i, isPrime(i));	
	};
	return 0;
}
