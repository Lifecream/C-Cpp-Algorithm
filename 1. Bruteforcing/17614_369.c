/*
백준 17614번
https://www.acmicpc.net/problem/17614
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void) {
	int n;
	scanf("%d",&n);
	int cnt = 0;
	for(int i = 1; i<=n; i++){
		int temp = i;
		while(temp){
			if(temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9) cnt++;
			temp /= 10;
		}
	}
	printf("%d",cnt);
	return 0;
}
