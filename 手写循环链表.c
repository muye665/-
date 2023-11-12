#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
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
	head->next = head;
	return head;
}

//头插法
void head_insert(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = head->next;
	head->next = node;
	head->data++;
} 

//尾插法
void tail_insert(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	Node* p = head;
	while(p->next != head){
		p = p->next;
	}
	p->next = node;
	node->next = head;
	head->data++;
}

//插入结点
void  add_node(Node* head, int data, int location){
	int cnt = 0;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	Node* p = head;
	while(p->next != head && cnt < location-1){
		p = p->next;
		cnt++;
	}
	if(p->next == head){
		return;
	}else{
		node->next = p->next;
		p->next = node;
		head->data++;
		return;
	} 
}

//删除节点
void delete_node(Node* head, int data){
	Node* previous = head;
	Node* current = head->next;
	while(current != head && current->data != data){
		previous = current;
		current = current->next;
	}
	if(current == head){
		printf("%d not found in the list\n");
		return;
	}else{
		previous->next = current->next;
		free(current);
		return;
	}
}

//查找节点
void find_node(Node* head, int data){
	Node* p = head->next;
	while(p != head){
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
	if(p == head){
		printf("This is an empty linked list\n");
		return;
	}
	printf("(");
	while(p != head){
		printf("%d", p->data);
		p = p->next;
		if(p != head)
			printf(" ");
	}
	printf(")\n");
	return;
}
