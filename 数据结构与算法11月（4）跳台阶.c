#include <stdio.h>

int memory[1000] = {0};//��������//������������������ظ����� 

int f(int x){
	if(x == 1){
		memory[1] = 1;
		return 1;
	}
	
	if(x == 2){
		memory[2] = 2;
		return 2;
	}
	
	if(memory[x-1] == 0 && memory[x-2] == 0){
		memory[x-1] = f(x-1);
		memory[x-2] = f(x-2);
		return memory[x-1]+memory[x-2];
	}
	if(memory[x-1] != 0 && memory[x-2] == 0){
		memory[x-2] = f(x-2);
		return memory[x-1]+memory[x-2];
	}
	if(memory[x-1] == 0 && memory[x-2] != 0){
		memory[x-1] = f(x-1);
		return memory[x-1]+memory[x-2];
	}
	if(memory[x-1] != 0 && memory[x-2] != 0){
		return memory[x-1]+memory[x-2];
	}
	printf("error");
}


int main(void)
{
	int n;	//n��̨��,f(n)=f(n-1)+f(n-2) 
	scanf("%d", &n);
	
	int sum = f(n);
	printf("��%d����ģʽ", sum);
	
	return 0;
}
