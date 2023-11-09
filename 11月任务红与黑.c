#include <stdio.h>

char a[20][20];
int cnt = 0;
int X, Y;


void judge(int x, int y, char a[20][20], int X, int Y);

int main(void){
	
	//读入长宽
	int i, j, m, n; 
	scanf("%d %d", &X, &Y);
	
	//读入所有字符
	for(i = 0; i< Y; i ++){   
		scanf("%s" , a[i]);
	}
	
	//寻找'@',并储存其坐标 
	for(i=0; i<Y; i++){ 
		for(j=0; j<X; j++){
			if(a[i][j]=='@'){
				m=i; n=j;
				cnt++;
				goto out;
			}
		}
	}out:
	
	//寻找@附近的 '.' 
	judge(n, m, a, X, Y);
	printf("%d", cnt);
	
	return 0;
}

void judge(int x, int y, char a[20][20], int X, int Y) {
	//向左寻找 
	if (a[y][x-1]=='.' && x!=0){
		a[y][x-1]='@'; cnt++;
		judge(x-1, y, a, X, Y);
	}
	//向右寻找 
	if(a[y][x+1]=='.' && x!=X-1){ 
		a[y][x+1]='@'; cnt++;
		judge(x+1, y, a, X, Y);
	}
	//向下寻找 
	if(a[y+1][x]=='.' && y!=Y-1){
		a[y+1][x]='@'; cnt++;
		judge(x, y+1, a, X, Y);
		
	}
	//向上寻找 
	if(a[y-1][x]=='.'&& y!=0){
		a[y-1][x]='@'; cnt++;
		judge(x, y-1, a, X, Y);
	}

	return;
}
