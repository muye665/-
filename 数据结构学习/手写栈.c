#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

Node* addhead();  //����ͷ���
void addstack(Node* head, int data);  //��ջ 
int pop(Node* head);  //��ջ
void printstack(Node* head);  //��ӡջ

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

//����ͷ��� 
Node* addhead(){
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//��ջ 
void addstack(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = head->next;
	head->next = node;
	head->data++;
}

//��ջ
int pop(Node* head){
	if(head->next == NULL){
		printf("It's an empty stack");
		return 0;
	}else{
		Node* p = head->next;
		head->next = p->next;
		
		//���س�ջ������
		int data = p->data;
		free(p);
		head->data--;
		return data;
	}
}

//��ӡջ
void printstack(Node* head){
	Node* p = head->next;
	while(p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
	return;
} 






