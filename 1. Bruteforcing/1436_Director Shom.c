/*
백준 1436번
https://www.acmicpc.net/problem/1436
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void) {
	int n;
	scanf("%d",&n);
	int count = 0;
	for(int i = 666;; i++){
		int m = i;
		while(m/100){
			if((m % 10) + (m / 10 % 10 * 10) + (m / 100 % 10 * 100) == 666){
				count++;
				break;
			}
			m /= 10;
		}
		if(n==count){
			printf("%d",i);
			break;
		}
	}
	return 0;
}
