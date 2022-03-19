/*
백준 9461번
https://www.acmicpc.net/problem/9461
*/

//algorithm: Dynamic_Programming

#include <stdio.h>

int main(void){
	int t;
	scanf("%d",&t);
	unsigned long long dp[101] = {0,1,1,1,2,2,3,4,};
	for(int i = 8; i<=100; i++){
		dp[i] = dp[i-1] + dp[i-5];
	}
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}
