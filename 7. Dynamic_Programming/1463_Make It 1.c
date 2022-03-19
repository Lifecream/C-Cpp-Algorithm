/*
백준 1463번
https://www.acmicpc.net/problem/1463
*/

//algorithm: Dynamic_Programming

#include <stdio.h>

int min(int a, int b){
	return a < b ? a : b;
}

int dp[1000001] = {0,};

int main(void) {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	int n;
	scanf("%d",&n);
	for(int i = 4; i<=1000001; i++){
		dp[i] = dp[i-1] + 1;
		if(i % 2 == 0)
			dp[i] = min(dp[i],dp[i/2]+1);
		if(i % 3 == 0)
			dp[i] = min(dp[i],dp[i/3]+1);
	}
	printf("%d",dp[n]);
	return 0;
}
