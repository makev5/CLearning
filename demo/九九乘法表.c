#include <stdio.h>
/*
	¾Å¾Å³Ë·¨±í 
*/
int main()  {
	int i,j;
	for(i=1; i<=9; i++){
		for(j=1; j<=i; j++){
			printf("%d*%d=%d\t",j, i, (i*j));
			if(i==j) printf("\n");
		}
	}
}
