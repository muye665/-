#include <stdio.h>

int memory[1000] = {0};//记忆数组//记忆搜索结果，避免重复计算 

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
	int n;	//n级台阶,f(n)=f(n-1)+f(n-2) 
	scanf("%d", &n);
	
	int sum = f(n);
	printf("有%d种跳模式", sum);
	
	return 0;
}
