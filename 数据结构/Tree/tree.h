//�㷨3 ��������ĵݹ��㷨

#include<iostream>
using namespace std;
typedef struct BiNode{				//����������
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

//���������˳������������
void CreateBiTree(BiTree &T){	
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else{							
		T=new BiTNode;
		T->data=ch;					//���ɸ����
		CreateBiTree(T->lchild);	//�ݹ鴴��������
		CreateBiTree(T->rchild);	//�ݹ鴴��������
	}								//else
}									//CreateBiTree

void PostOrderTraverse(BiTree T){  
	//�������������T�ĵݹ��㷨
	if(T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data;
	}
}
