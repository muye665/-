#include <stdio.h>

int main(void){
	
	//��������
	int n;
	int i, l;
	int p = 1;//i�У�l�У�a[i][l] 
	scanf("%d",&n);
	int a[1000][1000];
	
	//��������
	for(i = 0; i < n; i++){
		for(l = 0; l < p; l++){
			scanf("%d", &a[i][l]);
		}p++;
	}
	
//	p = 1;
//	for(i = 0; i < n; i++){
//		for(l = 0; l < p; l++){
//			printf("%d", a[i][l]);
//		}p++;
//	}
	
	//�Ƚ�·��
	p = n-1;
	for(i = n-2; i >= 0; i--){
		for(l = 0; l < p; l++){
			if(a[i+1][l] > a[i+1][l+1]){
				a[i][l] = a[i][l]+a[i+1][l];
			}
			else{
				a[i][l] = a[i][l]+a[i+1][l+1];
			}
		}p--;
	}
	printf("%d",a[0][0]);
	
	//������ 
	
	return 0;
} 
