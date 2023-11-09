#include <stdio.h>

int main()
{
	int num,i;
	scanf("%d", &num);
	
	int B[num];//gcd(B,9973)=1
	long int n[num];//n=A%9973 AΪ9973*k+n 
	long long int A[num];
	
	for(i=0; i<num; i++){
		scanf("%ld %d", &n[i], &B[i]);
		A[i]=n[i];
	}
	
	for(i=0; i<num ;i++){
		
		while(A[i] < B[i]){
			A[i] += 9973;
			//printf("1:%lld\n",A[i]);
		}
		
		while(A[i] % B[i] != 0){
			A[i] += 9973;
			//printf("2:%lld\n",A[i]);
		}
		printf("%lld ",(A[i] / B[i] % 9973));
	}
	
	return 0;
}
