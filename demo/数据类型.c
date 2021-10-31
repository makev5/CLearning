/*
  数据类型：
		（1）整数 
 		           char，short，int，long，longlong 
		（2）浮点数 
                   float，double，long double 
		（3）逻辑 
			       bool 
		（4）指针
		（5）自定义类型 
	名称：		int		long	double
	格式化：	%d		%ld		%lf 
	范围：char < short < int < float < double
    大小： 1个字节到16个字节 
    1个字节是8个比特
*/
#include <stdio.h> 

int main()
{
	int a;
	a = 6; 
	printf("sizeof(double)=%ld\n", sizeof(
	  double));
	printf("sizeof(a)=%ld\n", sizeof(a));
	return 0;
}
