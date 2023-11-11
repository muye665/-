#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next ;
}Node;

Node* int_head();  //����ͷָ��
void head_insert(Node* head, int data);  //ͷ�巨
void tail_insert(Node* head, int data);  //β�巨
void add_node(Node* head, int data, int location);  //������
void delete_node(Node* head, int data);  //ɾ���ڵ�
void find_node(Node* head, int data);  //���ҽڵ�
void printf_list(Node* head);  //��ӡ����

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

//����ͷָ��
Node* int_head(){
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}

//ͷ�巨
void head_insert(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = head->next;
	head->next = node;
	head->data++;
} 

//β�巨
void tail_insert(Node* head, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	Node* p = head;
	while(p->next != NULL){
		p = p->next;
	}
	p->next = node;
	head->data++;
}

//������
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
		p->next = node;
		head->data++;
		return;
	} 
}

//ɾ���ڵ�
void delete_node(Node* head, int data){
	Node* previous = head;
	Node* current = head->next;
	while(current != NULL && current->data != data){
		previous = current;
		current = current->next;
	}
	if(current == NULL){
		printf("%d not found in the list\n");
		return;
	}else{
		previous->next = current->next;
		free(current);
		return;
	}
}

//���ҽڵ�
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

//��ӡ����
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
