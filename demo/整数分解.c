#include <stdio.h>

int main(){
	int x;
	
	x = 7000;
	int mask = 1;
	int t = x;
	while(t > 9){
		t /= 10;
		mask *= 10;
	}
	printf("x=%d, mask=%d, t=%d\n", x, mask, t);
	
	do{
		int d = x % 10;
		printf("%d", d);
		if(mask > 9){
			printf(" ");
		}
		x /= 10;
	} while(x > 0);
	printf("\n");
	
	return 0;  
} 
