/*
   (1)��������������������ϲ�Ϊһ����������������Ҫ����������ʹ��ԭ����������
   �Ĵ洢�ռ䣬������ռ�������Ĵ洢�ռ䡣���в��������ظ������ݡ� 
*/ 
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1

typedef int ElemType;
typedef struct LNode{
	ElemType  data;
	struct LNode *next;
} LNode ,*LinkList;

LinkList pa, pb, pc, t;
LinkList La, Lb, Lc; 

int IintList (LinkList &L){
	L = new LNode;
	L->next=NULL;
	return OK;
}
void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc){ // �ϲ�����La��Lb���ϲ�����±�ʹ��ͷָ��Lcָ�� 
	pa=La->next;
	pb=Lb->next;
	// pa��pb�ֱ�������La ��L �Ĺ���ָ�룬��ʼ��Ϊ��Ӧ����ĵ�һ�����
	pc = Lc =La; // ��La��ͷ�����Ϊ Lc��ͷ���
    while(pa && pb){
	    if(pa->data<=pb->data){
	        pc->next=pa;
	        pc=pa;
			if(pa->data == pb->data)
				pb = pb->next;
	            pa = pa->next;		
	    }else{
	       pc->next=pb;
	       pc=pb; 
	       pb=pb->next;
		}
	}
   pc->next = pa ? pa : pb;  
   delete Lb;          
}

int main(){
	int i, n;
	IintList(La); 
	IintList(Lb);
	
    printf("����La��ĳ���n:");
	scanf("%d", &n);
	printf("��La˳���ֵ��");
	for(i = 0;i < n; i++){
		pa = new LNode; 
		scanf("%d",&pa->data);
		
		pa->next = La->next;
		La->next = pa;
	}
	printf("La������Ϊ:");
	pa = La->next;
	while (pa){
		printf("%5d",pa->data);
		pa = pa->next;
	}
	printf("\n����Lb��ĳ���n:");
	scanf("%d", &n);
	printf("��Lb˳���ֵ��");
	for(i = 0;i <n; i++){
		pb = new LNode;  
		scanf("%d",&pb->data);
		pb->next = Lb->next;
		Lb->next = pb;
	}
	printf("Lb������Ϊ��");
	pb = Lb->next;
	while (pb){
		printf("%5d",pb->data);
		pb = pb->next;
	}
	printf("\n");
	MergeList(La,Lb,Lc);
	t = La->next;
	printf("�ϲ�������Ϊ��");
		while(t){
			printf("%5d",t->data);
			t = t->next;
		}
		printf("\n");
}

