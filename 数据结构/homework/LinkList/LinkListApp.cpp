#include <stdio.h>
#include "LinkList.h"
//对线性表 l=（10,2,30,4,50,6）进行如下操作
int main()
{
	LinkList list=NULL;
	int n=6;
	ElemType a[6]={10, 2, 30, 4, 50, 6};
	
	CreateList_FArr(list, a, n);
	//1 头插法将 l存入单链表list 中，并遍历输出list
	cout<<"1 头插法将l存入单链表list中"<<endl;
	CreateList_F(list, n); // 头插法 
	TraveralList(list); //遍历输出list
	
	//2 在单链表list的第3个元素之前插入元素28，然后遍历输出list
	ListInsert_L(list, 3, 28);
	cout<<"2 在单链表list的第3个元素之前插入元素28"<<endl;
	TraveralList(list); //遍历输出list

	//3 删除单链表list的第3个元素，然后遍历输出list
	ElemType dele_elem;
	ListDelete_L(list,3,dele_elem);
	cout<<"3 删除单链表list的第3个元素是："<<dele_elem<<endl;
	TraveralList(list); //遍历输出list

    //2.1.1 在单链表list的元素4之前插入元素35，然后遍历输出list
    LinkList s=new LNode;
    s->data=35;
    //(1) 调用LocateELem_L（）先找到元素4结点的指针p
    LinkList p=LocateELem_L(list, 4); 
    //(2) 调用InsertNodeByPoint() 在p之前插入s
    InsertNodeByPoint(list, p, s);
    cout<<"2.1.1 在单链表list的元素4之前插入元素35"<<endl;
    TraveralList(list); //遍历输出list

    //2.1.2 请在头文件中编写InsertNodeByElem(),实现下面操作
    InsertNodeByElem(list, 4, 35);
    cout<<"2.1.2 在单链表list的元素4之前插入元素35"<<endl;
    TraveralList(list); //遍历输出list

    //3.1 删除单链表list的元素35，然后遍历输出list 
	DeleteNodeByElem(list,35);
	cout<<"3.1 删除单链表list的元素35"<<endl;
	TraveralList(list); //遍历输出list

    //4 用尾插法创建带头结点的单链表L,从数据文件中读取
    cout<<"4 尾插法将l存入单链表list中"<<endl;
    CreateList_R(list, n);
    TraveralList(list); //遍历输出list

	//5 合并有序的带头结点的单链表 lc=la+lb ,lc与la lb有序顺序一致，允许重复
	LinkList la,lb,lc;
    ElemType a_arr[4]={3,5,8,11};
	ElemType b_arr[7]={2,6,8,9,11,15,20};
	CreateList_FArr(la,a_arr,4);
	CreateList_FArr(lb,b_arr,7);
	cout<<"la lb is:"<<endl;
	TraveralList(la);
	TraveralList(lb);
	MergeList_L(la,lb,lc);
	cout<<"5 合并有序的带头结点的单链表 lc=la+lb ,lc与la lb有序顺序一致，允许重复"<<endl;
	TraveralList(lc);
	 
	//6 合并有序的带头结点的单链表 LC=LA+LB ,LC与LA LB有序顺序一致，不允许重复
	LinkList LA, LB, LC;
	ElemType A_arr[4]={3,5,8,11};
	ElemType B_arr[7]={2,6,8,9,11,15,20};
	CreateList_FArr(LA,A_arr,4);
	CreateList_FArr(LB,B_arr,7);
	cout<<"LA LB is:"<<endl;
	TraveralList(LA);
	TraveralList(LB);
	MergeList_L_NRepeat(LA,LB,LC);
	cout<<"6 合并有序的带头结点的单链表 LC=LA+LB ,LC与LA LB有序顺序一致，不允许重复"<<endl;
    TraveralList(LC);
    		  
	//7 P53(2_6)找单链表中值最大的结点，并输出该最大值(请自己完成)
	LinkList L;
	ElemType L_arr[6]={10, 2, 30, 4, 50, 6};
	CreateList_FArr(L,L_arr, 6);
	cout<<"7 链表L=（10,2,30,4,50,6）中最大的结点是："<<Max(L)<<endl;
	
    //8 P53(2-7)逆置单链表，并输出逆置后的单链表(请自己完成)
    cout<<"8 链表L=（10,2,30,4,50,6）逆置后的单链表："<<endl;
    LinkList LD;
	ElemType LD_arr[6]={10, 2, 30, 4, 50, 6};
	CreateList_FArr(LD,LD_arr, 6);
    InverseL(LD);
	TraveralList(LD);
    
    //9 P53(2-8)删除带头结点递增单链表中大于22小于45之间的结点(请自己完成)
    cout<<"9 链表L=（2,4,6,10,30,50）删除带头结点递增单链表中大于22小于45之间的结点后："<<endl;
    LinkList LE;
	ElemType LE_arr[6]={2,4,6,10,30,50};
	CreateList_FArr(LE,LE_arr, 6);
    DeleteMinMax(LE,22,45);
    TraveralList(LE);
    
    //10 P35(2_10)删除带头结点单链表中结点值是2的结点(请自己完成)
    cout<<"10 链表L=（10,2,30,4,50,6）删除带头结点单链表中结点值是2的结点后："<<endl;
    LinkList LF;
	ElemType LF_arr[6]={10, 2, 30, 4, 50, 6};
	CreateList_FArr(LF,LF_arr, 6);
    DeleteAllElem(LF, 2);
    TraveralList(LF);
    return 0;
    
}

