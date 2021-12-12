#include <stdio.h>
#include "LinkList.h"
//�����Ա� l=��10,2,30,4,50,6���������²���
int main()
{
	LinkList list=NULL;
	int n=6;
	ElemType a[6]={10, 2, 30, 4, 50, 6};
	
	CreateList_FArr(list, a, n);
	//1 ͷ�巨�� l���뵥����list �У����������list
	cout<<"1 ͷ�巨��l���뵥����list��"<<endl;
	CreateList_F(list, n); // ͷ�巨 
	TraveralList(list); //�������list
	
	//2 �ڵ�����list�ĵ�3��Ԫ��֮ǰ����Ԫ��28��Ȼ��������list
	ListInsert_L(list, 3, 28);
	cout<<"2 �ڵ�����list�ĵ�3��Ԫ��֮ǰ����Ԫ��28"<<endl;
	TraveralList(list); //�������list

	//3 ɾ��������list�ĵ�3��Ԫ�أ�Ȼ��������list
	ElemType dele_elem;
	ListDelete_L(list,3,dele_elem);
	cout<<"3 ɾ��������list�ĵ�3��Ԫ���ǣ�"<<dele_elem<<endl;
	TraveralList(list); //�������list

    //2.1.1 �ڵ�����list��Ԫ��4֮ǰ����Ԫ��35��Ȼ��������list
    LinkList s=new LNode;
    s->data=35;
    //(1) ����LocateELem_L�������ҵ�Ԫ��4����ָ��p
    LinkList p=LocateELem_L(list, 4); 
    //(2) ����InsertNodeByPoint() ��p֮ǰ����s
    InsertNodeByPoint(list, p, s);
    cout<<"2.1.1 �ڵ�����list��Ԫ��4֮ǰ����Ԫ��35"<<endl;
    TraveralList(list); //�������list

    //2.1.2 ����ͷ�ļ��б�дInsertNodeByElem(),ʵ���������
    InsertNodeByElem(list, 4, 35);
    cout<<"2.1.2 �ڵ�����list��Ԫ��4֮ǰ����Ԫ��35"<<endl;
    TraveralList(list); //�������list

    //3.1 ɾ��������list��Ԫ��35��Ȼ��������list 
	DeleteNodeByElem(list,35);
	cout<<"3.1 ɾ��������list��Ԫ��35"<<endl;
	TraveralList(list); //�������list

    //4 ��β�巨������ͷ���ĵ�����L,�������ļ��ж�ȡ
    cout<<"4 β�巨��l���뵥����list��"<<endl;
    CreateList_R(list, n);
    TraveralList(list); //�������list

	//5 �ϲ�����Ĵ�ͷ���ĵ����� lc=la+lb ,lc��la lb����˳��һ�£������ظ�
	LinkList la,lb,lc;
    ElemType a_arr[4]={3,5,8,11};
	ElemType b_arr[7]={2,6,8,9,11,15,20};
	CreateList_FArr(la,a_arr,4);
	CreateList_FArr(lb,b_arr,7);
	cout<<"la lb is:"<<endl;
	TraveralList(la);
	TraveralList(lb);
	MergeList_L(la,lb,lc);
	cout<<"5 �ϲ�����Ĵ�ͷ���ĵ����� lc=la+lb ,lc��la lb����˳��һ�£������ظ�"<<endl;
	TraveralList(lc);
	 
	//6 �ϲ�����Ĵ�ͷ���ĵ����� LC=LA+LB ,LC��LA LB����˳��һ�£��������ظ�
	LinkList LA, LB, LC;
	ElemType A_arr[4]={3,5,8,11};
	ElemType B_arr[7]={2,6,8,9,11,15,20};
	CreateList_FArr(LA,A_arr,4);
	CreateList_FArr(LB,B_arr,7);
	cout<<"LA LB is:"<<endl;
	TraveralList(LA);
	TraveralList(LB);
	MergeList_L_NRepeat(LA,LB,LC);
	cout<<"6 �ϲ�����Ĵ�ͷ���ĵ����� LC=LA+LB ,LC��LA LB����˳��һ�£��������ظ�"<<endl;
    TraveralList(LC);
    		  
	//7 P53(2_6)�ҵ�������ֵ���Ľ�㣬����������ֵ(���Լ����)
	LinkList L;
	ElemType L_arr[6]={10, 2, 30, 4, 50, 6};
	CreateList_FArr(L,L_arr, 6);
	cout<<"7 ����L=��10,2,30,4,50,6�������Ľ���ǣ�"<<Max(L)<<endl;
	
    //8 P53(2-7)���õ�������������ú�ĵ�����(���Լ����)
    cout<<"8 ����L=��10,2,30,4,50,6�����ú�ĵ�����"<<endl;
    LinkList LD;
	ElemType LD_arr[6]={10, 2, 30, 4, 50, 6};
	CreateList_FArr(LD,LD_arr, 6);
    InverseL(LD);
	TraveralList(LD);
    
    //9 P53(2-8)ɾ����ͷ�������������д���22С��45֮��Ľ��(���Լ����)
    cout<<"9 ����L=��2,4,6,10,30,50��ɾ����ͷ�������������д���22С��45֮��Ľ���"<<endl;
    LinkList LE;
	ElemType LE_arr[6]={2,4,6,10,30,50};
	CreateList_FArr(LE,LE_arr, 6);
    DeleteMinMax(LE,22,45);
    TraveralList(LE);
    
    //10 P35(2_10)ɾ����ͷ��㵥�����н��ֵ��2�Ľ��(���Լ����)
    cout<<"10 ����L=��10,2,30,4,50,6��ɾ����ͷ��㵥�����н��ֵ��2�Ľ���"<<endl;
    LinkList LF;
	ElemType LF_arr[6]={10, 2, 30, 4, 50, 6};
	CreateList_FArr(LF,LF_arr, 6);
    DeleteAllElem(LF, 2);
    TraveralList(LF);
    return 0;
    
}

