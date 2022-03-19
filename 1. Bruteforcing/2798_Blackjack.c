/*
백준 2798번
https://www.acmicpc.net/problem/2798
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[101] = {0,};
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	int max=0;
	for(int i=0; i<=n-3; i++){
		for(int j=i+1; j<=n-2; j++){
			for(int l=j+1; l<=n-1; l++){
				int sum = a[i]+a[j]+a[l];
				if(max<sum && sum<=m){
					max = a[i]+a[j]+a[l];
				}
			}
		}
	}
	printf("%d",max);
	return 0;
}
