/*
83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
	int elem;	//代表数据域
	struct Link * next;	//代表指针域，指向直接后继元素
}link;		//Link 为节点名，每个节点都是一个link结构体

//初始化链表
link * initLink(){
  int nums[5] = {1, 1, 2, 3, 3};
	int i;
	link * p = NULL;	//创建头指针
	link * temp = (link*)malloc(sizeof(link)); //创建首元素节点
	//首元素节点先初始化
	temp->elem = 1;
	temp->next = NULL;
	p = temp;	//头指针指向首元结点
	for (i=0;i<5;i++){
	  link * a = (link*)malloc(sizeof(link));
		a->elem = nums[i];
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

//遍历链表
void display(link *p){
	link * temp = p; //将temp指针重新指向头结点
	//只要temp 指针指向的借点是next不是 Null,就执行输出语句
	while (temp->next){
		temp=temp->next;
		printf("%d",temp->elem);
	}
	printf("\n");
}

//删除链表

link *deleteDuplicates(link *head){
	if(head == NULL){
		return head; //单链表为空，返回链表
	}
	link *lp;
	link *p = head; // 指针指向单链表
	lp = p; //最后链表返回的位置
	while(p != NULL && p->next != NULL){
		if(p->elem == p->next->elem){
			p->next = p->next->next;	//删除后者节点，继续遍历	
	}else{
		p = p->next;
	}	
	}
	return lp;
}


int main(){
	link *p = NULL;
	link *q = NULL;
	//初始化链表（1，1，2，3，3）
	printf("初始化链表为：\n");
	p = initLink();
	display(p);
	q = deleteDuplicates(p);
	display(q);
	return 0;
}


