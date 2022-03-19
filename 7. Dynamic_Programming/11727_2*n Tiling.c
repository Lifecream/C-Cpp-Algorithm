/*
백준 11726번
https://www.acmicpc.net/problem/11726
*/

//algorithm: Dynamic_Programming

#include <stdio.h>
#define DIV 10007

int main(void) {
	int dp[1001] = {0,1,2,};
	for(int i = 3; i<=1000; i++){
		dp[i] = (dp[i-1] % DIV + dp[i-2] % DIV) % DIV;
	}
	int n;
	scanf("%d",&n);
	printf("%d",dp[n]);
	return 0;
}
