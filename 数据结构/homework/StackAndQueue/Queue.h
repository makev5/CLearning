#include<iostream>
#include<fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char QElemType;
typedef int Status;
typedef char SElemType;

//- - - - - 队列的链式存储结构- - - - - 
typedef struct QNode {
	QElemType data;
	struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
	QueuePtr front; //队头指针
	QueuePtr rear; //队尾指针
} LinkQueue;

//算法3.16　链队的初始化
Status InitQueue(LinkQueue &Q) {//构造一个空队列Q
	Q.front = Q.rear = new QNode; //生成新结点作为头结点，队头和队尾指针指向此结点
	Q.front->next = NULL; //头结点的指针域置空
	return OK;
}

//算法3.17　链队的入队
Status EnQueue(LinkQueue &Q, QElemType e) {//插入元素e为Q的新的队尾元素
	QueuePtr p;
	p = new QNode; //为入队元素分配结点空间，用指针p指向
	p->data = e; //将新结点数据域置为e
	p->next = NULL;
	Q.rear->next = p; //将新结点插入到队尾
	Q.rear = p; //修改队尾指针
	return OK;
}

//算法3.18　链队的出队
Status DeQueue(LinkQueue &Q, QElemType &e) {//删除Q的队头元素，用e返回其值 
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR; //若队列空，则返回ERROR
	p = Q.front->next; //p指向队头元素
	e = p->data; //e保存队头元素的值
	Q.front->next = p->next; //修改头指针
	if (Q.rear == p)
		Q.rear = Q.front; //最后一个元素被删，队尾指针指向头结点
	delete p; //释放原队头元素的空间
	return OK;
}

//算法3.19　取链队的队头元素
SElemType GetHead(LinkQueue Q) {//返回Q的队头元素，不修改队头指针
	if (Q.front != Q.rear) //队列非空
		return Q.front->next->data; //返回队头元素的值，队头指针不变
}
