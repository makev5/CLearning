/*
  �������ͣ�
		��1������ 
 		           char��short��int��long��longlong 
		��2�������� 
                   float��double��long double 
		��3���߼� 
			       bool 
		��4��ָ��
		��5���Զ������� 
	���ƣ�		int		long	double
	��ʽ����	%d		%ld		%lf 
	��Χ��char < short < int < float < double
    ��С�� 1���ֽڵ�16���ֽ� 
    1���ֽ���8������
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
