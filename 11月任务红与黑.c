#include <stdio.h>

char a[20][20];
int cnt = 0;

void judge(int x, int y, char a[20][20]) {
	if (a[x-1][y]=='.'){
		a[x-1][y]='@'; cnt++;
		judge(x-1, y, a);
		
	}else if(a[x+1][y]=='.'){
		a[x+1][y]='@'; cnt++;
		judge(x-1, y, a);
		
	}else if(a[x][y-1]=='.'){
		a[x][y-1]='@'; cnt++;
		judge(x, y-1, a);
		
	}else if(a[x][y+1]=='.'){
		a[x][y+1]='@'; cnt++;
		judge(x, y+1, a);
	}
}

int main(void){
	int X, Y, i, j, m, n;
	scanf("%d %d", &X, &Y);
	
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			a[j][i]==0;
		}
	}
	

	for(i = 0; i< Y; i ++){
		scanf("%s" , a[i]);
	}
	for(i=0; i<Y; i++){
		for(j=0; j<X; j++){
			if(a[j][i]=='@'){
			m=j; n=i; cnt++;
			}
		}
	}
//	for(i = 0; i < Y ; i ++){
//		printf("%s" , a[i]);
//	}
	
//	for(i = 0; i < Y; i++){
//		if(a[j][i]=='@'){
//			m=j; n=i; cnt++; //@µÄ×ø±êÎª£¨m£¬n£© 
//		}
//	}
	
	for(i=0; i<Y; i++){
		for(j=0; j<X; j++){
			judge(m, n, a);
		}
	}
	printf("%d", cnt);
	
	return 0;
}
