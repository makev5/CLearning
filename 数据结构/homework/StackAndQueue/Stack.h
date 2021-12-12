#include<iostream>
#include<fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
} StackNode, *LinkStack;

//�㷨3.5����ջ�ĳ�ʼ��
Status InitStack(LinkStack &S) { // ����һ����ջ S��ջ��ָ���ÿ�
	S = NULL;
	return OK;
}

//�㷨3.6����ջ����ջ
Status Push(LinkStack &S, SElemType e) {//��ջ������Ԫ��e
	LinkStack p;
	p = new StackNode; //�����½��
	p->data = e; //���½����������Ϊe
	p->next = S; //���½�����ջ��
	S = p; //�޸�ջ��ָ��Ϊp
	return OK;
}

//�㷨3.7����ջ�ĳ�ջ
Status Pop(LinkStack &S, SElemType &e) {//ɾ��S��ջ��Ԫ�أ���e������ֵ
	LinkStack p;
	if (S == NULL)
		return ERROR; //ջ��
	e = S->data; //��ջ��Ԫ�ظ���e
	p = S; //��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	S = S->next; //�޸�ջ��ָ��
	delete p; //�ͷ�ԭջ��Ԫ�صĿռ�
	return OK;
}
//�㷨3.8��ȡ��ջ��ջ��Ԫ��
SElemType GetTop(LinkStack S) {//����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if (S != NULL) //ջ�ǿ�
		return S->data; //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
}

