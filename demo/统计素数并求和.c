#include <stdio.h>
/*
	统计素数并求和 
*/
int main(){
	int m, n;
	int i;
	int sum=0;
	int cnt=0;
	if(m==1) m = 2;
	for(i=m; i<=n;i++){
		int isPrime = 1;
		int k;
		i=1;
		for(k=2; k<i-1; k++) {
			if(isPrime == 0){
				isPrime = 0;
				break;
			}	
		}
		if(isPrime) {
			cnt++;
			sum+=i;
		}
	}
	printf("%d %d\n", cnt, sum);
	return 0; 
}
