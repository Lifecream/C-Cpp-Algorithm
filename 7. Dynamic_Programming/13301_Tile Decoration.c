/*
백준 13301번
https://www.acmicpc.net/problem/13301
*/

//algorithm: Dynamic_Programming

#include <stdio.h>

int main(void) {
	int n;
	unsigned long long f[81] = {0,1,1,};
	for(int i = 3; i<=80; i++){
		f[i] = f[i-1] + f[i-2];
	}
	scanf("%d",&n);
	if(n == 1) printf("4");
	else if(n == 2) printf("6");
	else if(n == 3)	printf("10");
	else printf("%lld",f[n] * 3 + f[n-1] * 2 + f[n-2] * 2 + f[n-3]);
	return 0;
}
