/*
백준 2748번
https://www.acmicpc.net/problem/2748
*/

//algorithm: Dynamic_Programming

#include <stdio.h>
#include <math.h>

unsigned long long a[1000000] = {0,};

int main(void){
	int n;
	a[0] = 0;
	a[1] = 1;
	for(int i = 2; i<=1000000; i++){
		a[i] = a[i-1] + a[i-2];
	}
	scanf("%d",&n);
	printf("%lld",a[n]);
}
