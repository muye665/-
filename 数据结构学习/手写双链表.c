#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *pre;
	int data;
	struct Node *next ;
}Node;

Node* int_head();  //创建头指针
void head_insert(Node* head, int data);  //头插法
void tail_insert(Node* head, int data);  //尾插法
void add_node(Node* head, int data, int location);  //插入结点
void delete_node(Node* head, int data);  //删除节点
void find_node(Node* head, int data);  //查找节点
void printf_list(Node* head);  //打印链表

int main(void){
	Node* head = int_head();
	printf_list(head);
	
	head_insert(head, 1);
	head_insert(head, 2);
	head_insert(head, 3);
	printf_list(head);
	
	tail_insert(head, 9);
	printf_list(head);
	
	add_node(head, 6, 2);
	printf_list(head);
	
	delete_node(head, 3);
	printf_list(head);
	
	find_node(head, 2);
	find_node(head, 3);
	
	printf("Tomorrow is another day!\n");
	return 0 ;
}

//创建头指针
Node* int_head(){
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->pre = NULL;
	head->next = NULL;
	return head;
}

//头插法
void head_insert(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	//判断是否为空表 
	if(head->next == NULL){
		node->next = head->next;
		node->pre = head;
		head->next = node;
	}else{
		node->next = head->next;
		node->pre = head;
		head->next->pre = node;
		head->next = node;
	}
	head->data++;
} 

//尾插法
void tail_insert(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	Node* p = head;
	while(p->next != NULL){
		p = p->next;
	}
	node->pre = p;
	p->next = node;
	head->data++;
}

//插入结点
void  add_node(Node* head, int data, int location){
	int cnt = 0;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	Node* p = head;
	while(p->next != NULL && cnt < location-1){
		p = p->next;
		cnt++;
	}
	if(p->next == NULL){
		return;
	}else{
		node->next = p->next;
		node->pre = p;
		p->next->pre = node;
		p->next = node; 
		head->data++;
		return;
	} 
}

//删除节点
void delete_node(Node* head, int data){
	Node* p = head->next;
	while(p != NULL && p->data != data){
		p = p->next;
	}
	if(p == NULL){
		printf("%d not found in the list\n", data);
		return;
	}else{
		p->next->pre = p->pre;
		p->pre->next = p->next;
		free(p);
		return;
	}
}

//查找节点
void find_node(Node* head, int data){
	Node* p = head->next;
	while(p != NULL){
		if(p->data == data){
			printf("%d found in the list\n", data);
			return;
		}
		p = p->next;
	}
	printf("%d not found in the list\n", data);
	return;
}

//打印链表
void printf_list(Node* head){
	Node* p = head->next;
	if(p == NULL){
		printf("This is an empty linked list\n");
		return;
	}
	printf("(");
	while(p != NULL){
		printf("%d", p->data);
		p = p->next;
		if(p != NULL)
			printf(" ");
	}
	printf(")\n");
	return;
}
