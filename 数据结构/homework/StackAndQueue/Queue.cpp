#include "Queue.h"

int main() {
	int choose, flag = 0;
	LinkQueue Q;
	QElemType e, j;
	cout << "1.��ʼ��\n";
	cout << "2.���\n";
	cout << "3.����ͷԪ��\n";
	cout << "4.����\n";
	cout << "0.�˳�\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
		case 1://�㷨3.16�����ӵĳ�ʼ��
			if (InitQueue(Q)) {
				flag = 1;
				cout << "�ɹ��Զ��н��г�ʼ��\n\n";
			} else
				cout << "��ʼ������ʧ��\n\n";
			break;
		case 2: {//�㷨3.17�����ӵ����
			fstream file;
			file.open("QNode.txt");     // QNode.txt �ļ����ݸ��ڱ���������������ݺ����Ϊ QNode.txt
			if (!file) {
				cout << "����δ�ҵ��ļ���\n\n" << endl;
				exit(ERROR);
			}
			if (flag) {
				flag = 1;
				cout << "��ӵ�Ԫ������Ϊ��\n";
				while (!file.eof()) {
					file >> j;
					if (file.fail())
						break;
					else {
						EnQueue(Q, j);
						cout << j << "  ";
					}
				}
				cout << endl << endl;
			} else
				cout << "����δ������������ѡ��\n\n";
			file.close();
		}
			break;
		case 3://�㷨3.19��ȡ���ӵĶ�ͷԪ��
			if (flag != -1 && flag != 0)
				cout << "��ͷԪ��Ϊ��\n" << GetHead(Q) << endl << endl;
			else
				cout << "��������Ԫ�أ�������ѡ��\n" << endl;
			break;
		case 4://�㷨3.18�����ӵĳ���
			cout << "���ε����Ķ�ͷԪ��Ϊ:\n";
			while (DeQueue(Q, e)) {
				flag = -1;
				cout << e << "  ";
			}
			cout << endl << endl;
			break;
		}
	}

	return 0;
}
