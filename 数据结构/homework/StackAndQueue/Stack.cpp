#include "Stack.h"

int main() {
	LinkStack s;
	int choose, flag = 0;
	SElemType j, t;
	cout << "1.初始化\n";
	cout << "2.入栈\n";
	cout << "3.读栈顶元素\n";
	cout << "4.出栈\n";
	cout << "0.退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1://算法3.5　链栈的初始化
			if (InitStack(s)) {
				flag = 1;
				cout << "成功对栈进行初始化\n\n";
			} else
				cout << "初始化栈失败\n\n";
			break;
		case 2: {//算法3.6　链栈的入栈
			fstream file;
			file.open("SqStack.txt");    //SqStack.txt 文件内容附在本代码后，请输入数据后另存为 SqStack.txt
			if (!file) {
				cout << "错误！未找到文件！\n\n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "进栈元素依次为：\n";
				while (!file.eof()) {
					file >> j;
					if (file.fail())
						break;
					else {
						Push(s, j);
						cout << j << "  ";
					}
				}
				cout << endl << endl;
			} else
				cout << "栈未建立，请重新选择\n\n";
			file.close();
		}
			break;
		case 3://算法3.8　取链栈的栈顶元素
			if (flag != -1 && flag != 0)
				cout << "栈顶元素为：\n" << GetTop(s) << endl << endl;
			else
				cout << "栈中无元素，请重新选择\n" << endl;
			break;
		case 4://算法3.7　链栈的出栈
			if (flag) {
				cout << "依次弹出的栈顶元素为:\n";
				while (Pop(s, t))
					cout << t << "  ";
				cout << endl << endl;
			} else
				cout << "栈未建立，请重新选择\n\n";
			break;
		}
	}
	return 0;
}

