/*
백준 15990번
https://www.acmicpc.net/problem/15990
*/

//algorithm: Dynamic_Programming

#include <stdio.h>
#define DIV 1000000009

unsigned long long dp[1000001][4] = {0,};

int main(void) {
	dp[1][1] = 1;
	dp[1][0] = 1;
	dp[2][2] = 1;
	dp[2][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	dp[3][0] = 3;
	for(int i = 4; i<=1000001; i++){
		dp[i][1] = (dp[i-1][2] % DIV + dp[i-1][3] % DIV) % DIV;
		dp[i][2] = (dp[i-2][1] % DIV + dp[i-2][3] % DIV) % DIV;
		dp[i][3] = (dp[i-3][1] % DIV + dp[i-3][2] % DIV) % DIV;
		dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % DIV;
	}
	int n;
	scanf("%d",&n);
	while(n--){
		int k;
		scanf("%d",&k);
		printf("%d\n",dp[k][0] % DIV);
	}
	return 0;
}
