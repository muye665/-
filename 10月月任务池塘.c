#include <stdio.h>
#define MAX 100

char a [MAX][MAX] ;

void tran(int x, int y, char a[MAX][MAX]){
	
	int j,i;
	
	for(i=y-1 ; i<=y+1 ; i++){
		for(j=x-1 ; j<=x+1 ; j++){
			
			if(a[j][i] == 'W' && !(j == x && i == y)){
				
				a[j][i] = 1;
				tran(j,i,a);
			}
		}
	}
}

int main(){
	int cnt = 0;
	int m,n,i,j; //wΪ��ˮ��1Ϊͳ�ƺ��ˮ
	
	scanf("%d %d",&m,&n) ;//mΪ�У�nΪ�� 
	
	for(i = 0; i < m ; i ++){  //iΪ�У�jΪ�� 
		scanf("%s" , a[i]);
	}
	
//	for (i = 0;i < m;i ++){
//		for(j = 0; j < n;j ++){
//			printf("%c",a[j][i]) ;
//		}
//	}printf("\n"); 
//			
//	for (i = 0;i < m;i ++){
//			printf("%s",a[i]) ;
//	}printf("\n"); 
			
	
	for (i = 0;i < m;i ++){
		for(j = 0; j < n;j ++){
			
			if(a[j][i] == 'W'){
				
				a[j][i] = 1 ;
				
				tran(j, i, a);
				
				cnt ++;
			}
		}
	}
	printf("%d",cnt);
	
	return 0 ;
} 
