#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

Node* addhead();  //创建头结点
void addstack(Node* head, int data);  //入栈 
int pop(Node* head);  //出栈
void printstack(Node* head);  //打印栈

int main(void){
	Node* head = addhead();
	addstack(head, 1);
	addstack(head, 2);
	addstack(head, 3);
	printstack(head);
	
	int a = pop(head);
	printf("a=%d\n", a);
	printstack(head);
	
	printf("\nTomorrow is another day!\n");
	return 0;
}

//创建头结点 
Node* addhead(){
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//入栈 
void addstack(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = head->next;
	head->next = node;
	head->data++;
}

//出栈
int pop(Node* head){
	if(head->next == NULL){
		printf("It's an empty stack");
		return 0;
	}else{
		Node* p = head->next;
		head->next = p->next;
		
		//返回出栈的数据
		int data = p->data;
		free(p);
		head->data--;
		return data;
	}
}

//打印栈
void printstack(Node* head){
	Node* p = head->next;
	while(p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
	return;
} 






