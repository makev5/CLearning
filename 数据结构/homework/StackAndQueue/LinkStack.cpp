#include "LinkStack.h"

int main() {//对于输入的任意一个非负十进制数，打印输出与其等值的八进制数
	int n, e;
	cout << "输入一个非负十进制数:" << endl;
	cin >> n;
	
	cout << n << "的八进制数:" << endl;
	conversion(n);
	return 0;
}
