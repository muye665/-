#include <stdio.h>

char a[20][20];
int cnt = 0;
int X, Y;


void judge(int x, int y, char a[20][20], int X, int Y);

int main(void){
	
	//���볤��
	int i, j, m, n; 
	scanf("%d %d", &X, &Y);
	
	//���������ַ�
	for(i = 0; i< Y; i ++){   
		scanf("%s" , a[i]);
	}
	
	//Ѱ��'@',������������ 
	for(i=0; i<Y; i++){ 
		for(j=0; j<X; j++){
			if(a[i][j]=='@'){
				m=i; n=j;
				cnt++;
				goto out;
			}
		}
	}out:
	
	//Ѱ��@������ '.' 
	judge(n, m, a, X, Y);
	printf("%d", cnt);
	
	return 0;
}

void judge(int x, int y, char a[20][20], int X, int Y) {
	//����Ѱ�� 
	if (a[y][x-1]=='.' && x!=0){
		a[y][x-1]='@'; cnt++;
		judge(x-1, y, a, X, Y);
	}
	//����Ѱ�� 
	if(a[y][x+1]=='.' && x!=X-1){ 
		a[y][x+1]='@'; cnt++;
		judge(x+1, y, a, X, Y);
	}
	//����Ѱ�� 
	if(a[y+1][x]=='.' && y!=Y-1){
		a[y+1][x]='@'; cnt++;
		judge(x, y+1, a, X, Y);
		
	}
	//����Ѱ�� 
	if(a[y-1][x]=='.'&& y!=0){
		a[y-1][x]='@'; cnt++;
		judge(x, y-1, a, X, Y);
	}

	return;
}
