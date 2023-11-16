#include <stdio.h>
#include <stdlib.h>

typedef struct String {
	char* data; //存放字符串
	int len; //字符串长度 
}String;

String* intString(){
	String* s = (String*)malloc(sizeof(String));
	s->data = NULL;  
	s->len = 0;
	return s;
}

void assignString(String* s, char* data){
	if(s->data != NULL){
		free(s->data);
	}
	int len = 0;
	char* temp = data;
	while(*temp != '\0'){//?‘\0’ 
		len++;
		temp++;
	}
	s->len = len;
	s->data = (char*)malloc(sizeof(char) * (len + 1));//记得开辟空间！！！有'0' 
	temp = data;
	int i;
	for(i = 0; i < len; i++, temp++){
		s->data[i] = *temp;
	}
}

void printString(String* s){
	int i;
	for(i = 0; i < s->len; i++){
		printf(i == 0 ? "%c" : "->%c", s->data[i]);
	}
	printf("\n");
}

void searchString(String* text, String* word){
	int t = 0;
	int w = 0;
	while(t < text->len && w < word->len){
		if(text->data[t] == word->data[w]){
			t++;
			w++;
		}else{
			t = t - w + 1;
			w = 0;
		}
	}
	int i;
	if(w == word->len){
		printf("Found it\n");
		return;
	}else{
		printf("Not found it\n");
		return;
	}
}

int main(void){
	String* s1 = intString();
	assignString(s1, "Hamburger love you");
	printString(s1);
	
	String* s2 = intString();
	assignString(s2, "love");
	printString(s2);
	
	searchString(s1,s2);
	
	return 0;
} 
