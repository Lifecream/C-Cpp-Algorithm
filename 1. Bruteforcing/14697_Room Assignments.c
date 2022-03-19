/*
백준 14697번
https://www.acmicpc.net/problem/14697
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void) {
	int a,b,c,n;
	scanf("%d %d %d %d",&a,&b,&c,&n);
	int t = 0;
	for(int i = 0; i*a<=n; i++){
		for(int j = 0; j*b<=n; j++){
			for(int l = 0; l*c<=n; l++){
				if(t==1) continue;
				if(a*i + b*j + c*l == n) t = 1;
			}
		}
	}
	printf("%d",t);
	return 0;
}
