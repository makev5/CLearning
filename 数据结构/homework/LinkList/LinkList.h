#include<iostream>
#define OK 1
#define ERROR 0

using namespace std;

typedef int Status;
typedef int ElemType;

//������Ĵ洢�ṹ 
typedef struct LNode{  //P30
	ElemType data;      		//������
	struct LNode *next;   	//ָ����
}LNode,*LinkList;

LinkList p, q, r, pre, s;
LinkList pmax;

//ͷ�巨 
void CreateList_F(LinkList &L,int n){   //P36
	L=new LNode; 
	L->next=NULL; //�Ƚ���һ����ͷ���ĵ����� 
	cout<<"enter "<<n<<" data:"<<endl;
 	for(int i=n;i>0;--i){ 
        p=new LNode; //�����½�� 
        cin>>p->data; //����Ԫ��ֵ 
        p->next=L->next;L->next=p; 	//���뵽��ͷ 
     } 
}//CreateList_F 

//β�巨
void CreateList_R(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;
	r=L;
    cout<<"enter "<<n<<" data:"<<endl;
    for(int i=0;i<n;i++){
    	p=new LNode;
    	cin>>p->data;
    	p->next=NULL;
    	r->next=p;
    	r=p;
	}
} 

//�������
void TraveralList(LinkList L)
{
	LinkList p=L->next;
	cout<<"traveral list:"<<endl;
	while(p!=NULL)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}

void CreateList_FArr(LinkList &L,ElemType a[],int n){  
	 L=new LNode; 
     L->next=NULL; //�Ƚ���һ����ͷ���ĵ����� 
     for(int i=n-1;i>=0;--i){ 
        p=new LNode; //�����½�� 
        p->data=a[i]; //����Ԫ��ֵ 
        p->next=L->next;L->next=p; 	//���뵽��ͷ 
     } 
}//CreateList_F 


Status ListInsert_L(LinkList &L,int i,ElemType e){ 
	//��L�е�i��Ԫ��֮ǰ��������Ԫ��e  �����㷨2.9 
    LinkList p=L; int j=0; 
      while(p&&j<i-1){p=p->next;++j;}	//Ѱ�ҵ�i?1����� 
      if(!p||j>i-1) return ERROR;	//i���ڱ� + 1����С��1  
      LinkList s=new LNode;			//�����½��s 
      s->data=e;      		           //�����s����������Ϊe 
      s->next=p->next;	   	          //�����s����L�� 
      p->next=s; 
      return OK; 
}//ListInsert_L 


Status ListDelete_L(LinkList &L,int i,ElemType &e){
	 //�����Ա�L�е�i������Ԫ��ɾ�� �㷨2.10
  LinkList  p=L;int j=0; 
    while(p->next &&j<i-1){//Ѱ�ҵ�i����㣬����pָ����ǰ�� 
        p=p->next; ++j; 
    } 
    if(!(p->next)||j>i-1) return ERROR; //ɾ��λ�ò����� 
    LinkList q=p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ� 
    p->next=q->next; 	//�ı�ɾ�����ǰ������ָ���� 
    e=q->data; 	//����ɾ������������ 
    delete q; 	//�ͷ�ɾ�����Ŀռ� 
 return OK; 
}//ListDelete_L 

 
LinkList LocateELem_L(LinkList L,ElemType e) {
 //�ڴ�ͷ���ĵ�����L�в���ֵΪe�Ľ���ָ��  �㷨2.8
 //����L��ֵΪe������Ԫ�صĵ�ַ������ʧ�ܷ���NULL
 LinkList p=L->next;  //pָ����Ԫ���
  while(p &&p->data!=e)  
        p=p->next;                		
  return p; 	
} 

void InsertNodeByPoint(LinkList L,LinkList p ,LinkList s)
{//��֪L�Ǵ�ͷ���ĵ������ͷָ�룬pָ��ĳ���ݽ�㣬��s���뵽p֮ǰ
	LinkList q=L;
	while(q->next!=p) //��p��ǰ��ָ��q
		q=q->next;
	s->next=p;
	q->next=s;
}

//��ֵ���� 
Status InsertNodeByElem(LinkList L, ElemType elem, ElemType inse_elem)
{//��֪L�Ǵ�ͷ���ĵ������ͷָ��,Ҫ��������Ԫ��elem֮ǰ����Ԫ��inse_elem
    p=L;
    int j=0;
	while(p && p->next->data!=elem) //��elem��ǰ��ָ��q
		p=p->next;
	q=new LNode;
	p->data=inse_elem;
	q->next=p->next;
	q->next=q;
	return OK;
}

void DeleteNodeByElem(LinkList L,ElemType elem)
{//��֪L�Ǵ�ͷ���ĵ������ͷָ�룬ɾ��Ԫ��elem
	LinkList q=L;
	while(q->next->data!=elem) //��elem��ǰ��ָ��q
		q=q->next;
	LinkList p=q->next;  //pָ��ɾ���
	q->next=p->next;
	delete p;	
}


void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	//�����㷨2.16
	//�ϲ�����Ĵ�ͷ���ĵ����� lc=la+lb ,lc��la lb����˳��һ�£������ظ�
   LinkList pa,pb,pc; //pcָ��β���
   pa=La->next;  pb=Lb->next;
   pc=Lc=La;             //��La��ͷ�����ΪLc��ͷ��� 
   while(pa && pb){
      if(pa->data<=pb->data){ pc->next=pa;pc=pa;pa=pa->next;}
      else{ pc->next=pb; pc=pb; pb=pb->next;}
   }
   pc->next=pa?pa:pb;    //����ʣ���  
   delete Lb;             //�ͷ�Lb��ͷ���
}  

void MergeList_L_NRepeat(LinkList &La,LinkList &Lb,LinkList &Lc){
	//�����㷨2.17
	//�ϲ�����Ĵ�ͷ���ĵ����� lc=la+lb ,lc��la lb����˳��һ�£��������ظ�
	LinkList pa,pb,pc,q; //pcָ��β���
	pa=La->next;  pb=Lb->next;
   pc=Lc=La;             //��La��ͷ�����ΪLc��ͷ��� 
   while(pa && pb){
      if(pa->data<=pb->data)
		  if(pa->data<pb->data) //paС��pb,����pa,pa����
	        { pc->next=pa;pc=pa;pa=pa->next;}
		  else //pa����pb
		  {   pc->next=pa;pc=pa;pa=pa->next;    //����pa,pa����
	          q=pb;pb=pb->next;delete q; //ɾ��pb ,pb����
		  }
      else //pbС��pa,����pb,pb����
	  { pc->next=pb; pc=pb; pb=pb->next;}
   }
   pc->next=pa?pa:pb;    //����ʣ���  
   delete Lb;             //�ͷ�Lb��ͷ���
}  

ElemType Max (LinkList L){
    //P53(2_6)�㷨
	if(L->next==NULL) return ERROR;
	pmax=L->next; //�ٶ���һ����������ݾ������ֵ
    p=L->next->next;
	while(p != NULL ){//�����һ��������
		if(p->data > pmax->data) pmax=p;//���p��ֵ����pmax��ֵ�������¸�ֵ
		p=p->next;//��������
	}
	return pmax->data;
}

//���õ����� 
void InverseL(LinkList &L) {
    // ���ô�ͷ���ĵ����� L  P53(2_7)�㷨
    p=L->next;  L->next=NULL;
    while (p) {
        q=p->next;    // qָ��*p�ĺ��
        p->next=L->next;
        L->next=p;       // *p������ͷ���֮��
        p = q;
    }
}

//ɾ����ͷ�������������д���minkС��maxk֮��Ľ�� 
void DeleteMinMax(LinkList &L, int mink, int maxk) {//P53(2_8)�㷨
   p=L->next; //��Ԫ���
   while (p && p->data<=mink){ 
         pre=p;  
	     p=p->next; 
	} //���ҵ�һ��ֵ>mink�Ľ��
   if (p) 
   {while (p && p->data<maxk)  
        p=p->next;
        // ���ҵ�һ��ֵ ��maxk�Ľ��
        q=pre->next;   
		pre->next=p;  // �޸�ָ��
        while (q!=p){  
             s=q->next;  
			 delete q;  
			 q=s; 
		} // �ͷŽ��ռ�
   }//if
}

//ɾ����ͷ��㵥�����н��ֵ��elem�Ľ��
void  DeleteAllElem(LinkList L,ElemType elem){ //P53(2_10)�㷨
	LinkList p=L->next;
	LinkList pre=L;
		while(p)
	    {	
	     if(p->data==elem){			
	         LinkList q=p;//qָ��ǰ���			
	         p=p->next;			
	         pre->next=p;//ɾ��q���			
	         delete q;//�ͷ�q���Ŀռ� 		
	    }else{			
	         pre=p;			
	         p=p->next;		
	    }	
	}
}



