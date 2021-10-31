#include <stdio.h>
#include <math.h>

/*
  去掉偶数后，从3到x-1，每次加2 
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
		printf("%d是否是素数：%d\n", i, isPrime(i));	
	};
	return 0;
}
