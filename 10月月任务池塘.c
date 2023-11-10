#include <stdio.h>
#define MAX 100

//11.10修改：添加越界判断，提高代码可读性 

char a [MAX][MAX] ;

//查找'W'周围连着的的'W' 
void tran(int x, int y, char a[MAX][MAX], int m, int n){
	int j,i;
	for(i=y-1 ; i<=y+1 ; i++){
		for(j=x-1 ; j<=x+1 ; j++){
			
			//判断是否越界 
			if(j >= 0 && j < m && i>=0 && i < n && 
			a[j][i] == 'W' && !(j == x && i == y)){
				a[j][i] = 1;
				tran(j,i,a,m,n);
			}
		}
	}
}

int main(void){
	
	//w为新水，1为统计后的水
	int cnt = 0;
	int m,n,i,j; 
	
	//m为列，n为行 
	scanf("%d %d",&m,&n) ;
	
	//i为列，j为行 
	for(i = 0; i < m ; i ++){  
		scanf("%s" , a[i]);
	}
	
	//在数组中查找'W' 
	for (i = 0;i < m;i ++){
		for(j = 0; j < n;j ++){
			
			//找到'W'并换成'O'，避免重复统计 
			if(a[j][i] == 'W'){
				a[j][i] = 'O' ;
				tran(j, i, a,m,n);
				cnt ++;
			}
		}
	}
	printf("%d",cnt);
	
	return 0 ;
} 
