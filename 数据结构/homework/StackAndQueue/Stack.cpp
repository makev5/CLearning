#include "Stack.h"

int main() {
	LinkStack s;
	int choose, flag = 0;
	SElemType j, t;
	cout << "1.��ʼ��\n";
	cout << "2.��ջ\n";
	cout << "3.��ջ��Ԫ��\n";
	cout << "4.��ջ\n";
	cout << "0.�˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1://�㷨3.5����ջ�ĳ�ʼ��
			if (InitStack(s)) {
				flag = 1;
				cout << "�ɹ���ջ���г�ʼ��\n\n";
			} else
				cout << "��ʼ��ջʧ��\n\n";
			break;
		case 2: {//�㷨3.6����ջ����ջ
			fstream file;
			file.open("SqStack.txt");    //SqStack.txt �ļ����ݸ��ڱ���������������ݺ����Ϊ SqStack.txt
			if (!file) {
				cout << "����δ�ҵ��ļ���\n\n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "��ջԪ������Ϊ��\n";
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
				cout << "ջδ������������ѡ��\n\n";
			file.close();
		}
			break;
		case 3://�㷨3.8��ȡ��ջ��ջ��Ԫ��
			if (flag != -1 && flag != 0)
				cout << "ջ��Ԫ��Ϊ��\n" << GetTop(s) << endl << endl;
			else
				cout << "ջ����Ԫ�أ�������ѡ��\n" << endl;
			break;
		case 4://�㷨3.7����ջ�ĳ�ջ
			if (flag) {
				cout << "���ε�����ջ��Ԫ��Ϊ:\n";
				while (Pop(s, t))
					cout << t << "  ";
				cout << endl << endl;
			} else
				cout << "ջδ������������ѡ��\n\n";
			break;
		}
	}
	return 0;
}

