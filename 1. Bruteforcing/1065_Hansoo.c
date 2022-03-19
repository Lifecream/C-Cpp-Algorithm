/*
백준 1065번
https://www.acmicpc.net/problem/1065
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int a,b,count=0;
	int sub;
	for(int i = 1; i<=n; i++){
		a=i;
		b=0;
		sub = (a % 10 - (a/10)%10);
		while(a){
			if(a/10 !=0 && sub != a%10 - (a/10)%10){
				b=1;
			}
			a/=10;
		}
		if(b!=1){
			count ++;
		}
	}
	printf("%d",count);
	return 0;
}
