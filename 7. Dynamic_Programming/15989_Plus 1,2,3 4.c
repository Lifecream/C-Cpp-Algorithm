/*
백준 15989번
https://www.acmicpc.net/problem/15989
*/

//algorithm: Dynamic_Programming

#include <stdio.h>

unsigned long long dp[1000001][4] = {0,};

int main(void) {
	dp[1][1] = 1;
	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[2][0] = 2;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	dp[3][0] = 3;
	for(int i = 4; i<=10000; i++){
		dp[i][1] = 1;
		dp[i][2] = dp[i-2][1] + dp[i-2][2];
		dp[i][3] = dp[i-3][1] + dp[i-3][2]+ dp[i-3][3];
		dp[i][0] = dp[i][1] + dp[i][2] + dp[i][3];
	}
	int n;
	scanf("%d",&n);
	while(n--){
		int k;
		scanf("%d",&k);
		printf("%d\n",dp[k][0]);
	}
	return 0;
}
