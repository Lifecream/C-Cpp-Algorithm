/*
백준 2231번
https://www.acmicpc.net/problem/2231
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int backup = i;
		int sum = i;
		while(backup){
			sum += backup % 10;
			backup /= 10;
		}
		if(sum == n){
			printf("%d",i);
			return 0;
		}
	}
	printf("0");
	return 0;
}
