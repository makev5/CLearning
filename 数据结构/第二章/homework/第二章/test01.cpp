/*
   (1)将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表
   的存储空间，不另外占用其他的存储空间。表中不允许有重复的数据。 
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
void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc){ // 合并链表La和Lb，合并后的新表使用头指针Lc指向 
	pa=La->next;
	pb=Lb->next;
	// pa和pb分别是链表La 和L 的工作指针，初始化为相应链表的第一个结点
	pc = Lc =La; // 用La的头结点作为 Lc的头结点
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
	
    printf("输入La表的长度n:");
	scanf("%d", &n);
	printf("向La顺序表赋值：");
	for(i = 0;i < n; i++){
		pa = new LNode; 
		scanf("%d",&pa->data);
		
		pa->next = La->next;
		La->next = pa;
	}
	printf("La的数据为:");
	pa = La->next;
	while (pa){
		printf("%5d",pa->data);
		pa = pa->next;
	}
	printf("\n输入Lb表的长度n:");
	scanf("%d", &n);
	printf("向Lb顺序表赋值：");
	for(i = 0;i <n; i++){
		pb = new LNode;  
		scanf("%d",&pb->data);
		pb->next = Lb->next;
		Lb->next = pb;
	}
	printf("Lb的数据为：");
	pb = Lb->next;
	while (pb){
		printf("%5d",pb->data);
		pb = pb->next;
	}
	printf("\n");
	MergeList(La,Lb,Lc);
	t = La->next;
	printf("合并后链表为：");
		while(t){
			printf("%5d",t->data);
			t = t->next;
		}
		printf("\n");
}

