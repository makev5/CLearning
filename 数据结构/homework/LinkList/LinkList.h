#include<iostream>
#define OK 1
#define ERROR 0

using namespace std;

typedef int Status;
typedef int ElemType;

//单链表的存储结构 
typedef struct LNode{  //P30
	ElemType data;      		//数据域
	struct LNode *next;   	//指针域
}LNode,*LinkList;

LinkList p, q, r, pre, s;
LinkList pmax;

//头插法 
void CreateList_F(LinkList &L,int n){   //P36
	L=new LNode; 
	L->next=NULL; //先建立一个带头结点的单链表 
	cout<<"enter "<<n<<" data:"<<endl;
 	for(int i=n;i>0;--i){ 
        p=new LNode; //生成新结点 
        cin>>p->data; //输入元素值 
        p->next=L->next;L->next=p; 	//插入到表头 
     } 
}//CreateList_F 

//尾插法
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

//遍历输出
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
     L->next=NULL; //先建立一个带头结点的单链表 
     for(int i=n-1;i>=0;--i){ 
        p=new LNode; //生成新结点 
        p->data=a[i]; //输入元素值 
        p->next=L->next;L->next=p; 	//插入到表头 
     } 
}//CreateList_F 


Status ListInsert_L(LinkList &L,int i,ElemType e){ 
	//在L中第i个元素之前插入数据元素e  书中算法2.9 
    LinkList p=L; int j=0; 
      while(p&&j<i-1){p=p->next;++j;}	//寻找第i?1个结点 
      if(!p||j>i-1) return ERROR;	//i大于表长 + 1或者小于1  
      LinkList s=new LNode;			//生成新结点s 
      s->data=e;      		           //将结点s的数据域置为e 
      s->next=p->next;	   	          //将结点s插入L中 
      p->next=s; 
      return OK; 
}//ListInsert_L 


Status ListDelete_L(LinkList &L,int i,ElemType &e){
	 //将线性表L中第i个数据元素删除 算法2.10
  LinkList  p=L;int j=0; 
    while(p->next &&j<i-1){//寻找第i个结点，并令p指向其前驱 
        p=p->next; ++j; 
    } 
    if(!(p->next)||j>i-1) return ERROR; //删除位置不合理 
    LinkList q=p->next; //临时保存被删结点的地址以备释放 
    p->next=q->next; 	//改变删除结点前驱结点的指针域 
    e=q->data; 	//保存删除结点的数据域 
    delete q; 	//释放删除结点的空间 
 return OK; 
}//ListDelete_L 

 
LinkList LocateELem_L(LinkList L,ElemType e) {
 //在带头结点的单链表L中查找值为e的结点的指针  算法2.8
 //返回L中值为e的数据元素的地址，查找失败返回NULL
 LinkList p=L->next;  //p指向首元结点
  while(p &&p->data!=e)  
        p=p->next;                		
  return p; 	
} 

void InsertNodeByPoint(LinkList L,LinkList p ,LinkList s)
{//已知L是带头结点的单链表的头指针，p指向某数据结点，把s插入到p之前
	LinkList q=L;
	while(q->next!=p) //找p的前驱指针q
		q=q->next;
	s->next=p;
	q->next=s;
}

//按值插入 
Status InsertNodeByElem(LinkList L, ElemType elem, ElemType inse_elem)
{//已知L是带头结点的单链表的头指针,要求在数据元素elem之前插入元素inse_elem
    p=L;
    int j=0;
	while(p && p->next->data!=elem) //找elem的前驱指针q
		p=p->next;
	q=new LNode;
	p->data=inse_elem;
	q->next=p->next;
	q->next=q;
	return OK;
}

void DeleteNodeByElem(LinkList L,ElemType elem)
{//已知L是带头结点的单链表的头指针，删除元素elem
	LinkList q=L;
	while(q->next->data!=elem) //找elem的前驱指针q
		q=q->next;
	LinkList p=q->next;  //p指向被删结点
	q->next=p->next;
	delete p;	
}


void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	//书中算法2.16
	//合并有序的带头结点的单链表 lc=la+lb ,lc与la lb有序顺序一致，允许重复
   LinkList pa,pb,pc; //pc指向尾结点
   pa=La->next;  pb=Lb->next;
   pc=Lc=La;             //用La的头结点作为Lc的头结点 
   while(pa && pb){
      if(pa->data<=pb->data){ pc->next=pa;pc=pa;pa=pa->next;}
      else{ pc->next=pb; pc=pb; pb=pb->next;}
   }
   pc->next=pa?pa:pb;    //插入剩余段  
   delete Lb;             //释放Lb的头结点
}  

void MergeList_L_NRepeat(LinkList &La,LinkList &Lb,LinkList &Lc){
	//书中算法2.17
	//合并有序的带头结点的单链表 lc=la+lb ,lc与la lb有序顺序一致，不允许重复
	LinkList pa,pb,pc,q; //pc指向尾结点
	pa=La->next;  pb=Lb->next;
   pc=Lc=La;             //用La的头结点作为Lc的头结点 
   while(pa && pb){
      if(pa->data<=pb->data)
		  if(pa->data<pb->data) //pa小于pb,链接pa,pa后移
	        { pc->next=pa;pc=pa;pa=pa->next;}
		  else //pa等于pb
		  {   pc->next=pa;pc=pa;pa=pa->next;    //链接pa,pa后移
	          q=pb;pb=pb->next;delete q; //删除pb ,pb后移
		  }
      else //pb小于pa,链接pb,pb后移
	  { pc->next=pb; pc=pb; pb=pb->next;}
   }
   pc->next=pa?pa:pb;    //插入剩余段  
   delete Lb;             //释放Lb的头结点
}  

ElemType Max (LinkList L){
    //P53(2_6)算法
	if(L->next==NULL) return ERROR;
	pmax=L->next; //假定第一个结点中数据具有最大值
    p=L->next->next;
	while(p != NULL ){//如果下一个结点存在
		if(p->data > pmax->data) pmax=p;//如果p的值大于pmax的值，则重新赋值
		p=p->next;//遍历链表
	}
	return pmax->data;
}

//逆置单链表 
void InverseL(LinkList &L) {
    // 逆置带头结点的单链表 L  P53(2_7)算法
    p=L->next;  L->next=NULL;
    while (p) {
        q=p->next;    // q指向*p的后继
        p->next=L->next;
        L->next=p;       // *p插入在头结点之后
        p = q;
    }
}

//删除带头结点递增单链表中大于mink小于maxk之间的结点 
void DeleteMinMax(LinkList &L, int mink, int maxk) {//P53(2_8)算法
   p=L->next; //首元结点
   while (p && p->data<=mink){ 
         pre=p;  
	     p=p->next; 
	} //查找第一个值>mink的结点
   if (p) 
   {while (p && p->data<maxk)  
        p=p->next;
        // 查找第一个值 ≥maxk的结点
        q=pre->next;   
		pre->next=p;  // 修改指针
        while (q!=p){  
             s=q->next;  
			 delete q;  
			 q=s; 
		} // 释放结点空间
   }//if
}

//删除带头结点单链表中结点值是elem的结点
void  DeleteAllElem(LinkList L,ElemType elem){ //P53(2_10)算法
	LinkList p=L->next;
	LinkList pre=L;
		while(p)
	    {	
	     if(p->data==elem){			
	         LinkList q=p;//q指向当前结点			
	         p=p->next;			
	         pre->next=p;//删除q结点			
	         delete q;//释放q结点的空间 		
	    }else{			
	         pre=p;			
	         p=p->next;		
	    }	
	}
}



