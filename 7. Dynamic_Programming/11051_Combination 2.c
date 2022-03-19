/*
백준 11051번
https://www.acmicpc.net/problem/11051
*/

//algorithm: Dynamic_Programming

#include <stdio.h>

int dp[1001][1001] = {0,};

int main(void) {
	int n,k;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i = 2; i<=1000; i++){
		for(int j = 0; j<=1000; j++){
			if(j == 0 || j == i){
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
		}
	}
	scanf("%d %d",&n,&k);
	printf("%d",dp[n][k]);
	return 0;
}
