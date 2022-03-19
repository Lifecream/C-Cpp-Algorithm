/*
백준 1793번
https://www.acmicpc.net/problem/1793
*/

//algorithm: Dynamic_Programming

#include<stdio.h>

int dp[251][121];

void Function(void){
	dp[0][0] = 1;
	dp[1][0] = 1;
	for(int i = 2; i<=250; i++){	//dp[i][j] = dp[i-1][j] + dp[i-2][j] *2
		for(int j = 0; j<120; j++){
			dp[i][j] += dp[i-1][j] + (2*dp[i-2][j]) ;
			dp[i][j+1] += dp[i][j] / 10;
			dp[i][j] %= 10;
		}
	}
}

int main(void){
	Function();
	int a,b;
	while(scanf("%d",&a) != EOF){
		int f = 0;
		for(int i = 120; i>=0; i--){
			if(dp[a][i]) f=1;
			if(f) printf("%d", dp[a][i]);
		}
		printf("\n");
	}
	return 0;
}
