#include <stdio.h>
#define MAX 100

//11.10�޸ģ����Խ���жϣ���ߴ���ɶ��� 

char a [MAX][MAX] ;

//����'W'��Χ���ŵĵ�'W' 
void tran(int x, int y, char a[MAX][MAX], int m, int n){
	int j,i;
	for(i=y-1 ; i<=y+1 ; i++){
		for(j=x-1 ; j<=x+1 ; j++){
			
			//�ж��Ƿ�Խ�� 
			if(j >= 0 && j < m && i>=0 && i < n && 
			a[j][i] == 'W' && !(j == x && i == y)){
				a[j][i] = 1;
				tran(j,i,a,m,n);
			}
		}
	}
}

int main(void){
	
	//wΪ��ˮ��1Ϊͳ�ƺ��ˮ
	int cnt = 0;
	int m,n,i,j; 
	
	//mΪ�У�nΪ�� 
	scanf("%d %d",&m,&n) ;
	
	//iΪ�У�jΪ�� 
	for(i = 0; i < m ; i ++){  
		scanf("%s" , a[i]);
	}
	
	//�������в���'W' 
	for (i = 0;i < m;i ++){
		for(j = 0; j < n;j ++){
			
			//�ҵ�'W'������'O'�������ظ�ͳ�� 
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
