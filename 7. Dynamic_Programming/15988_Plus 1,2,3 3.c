/*
백준 15988번
https://www.acmicpc.net/problem/15988
*/

//algorithm: Dynamic_Programming

#include <stdio.h>
#define DIV 1000000009

unsigned long long dp[1000001] = {0,1,2,4,};

int main(void) {
	for(int i = 4; i<=1000001; i++){
		dp[i] = (dp[i-1] % DIV + dp[i-2] % DIV + dp[i-3] % DIV) % DIV;
	}
	int n;
	scanf("%d",&n);
	while(n--){
		int k;
		scanf("%d",&k);
		printf("%lld\n",dp[k] % DIV);
	}
	return 0;
}
