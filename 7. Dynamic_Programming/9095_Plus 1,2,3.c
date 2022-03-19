/*
백준 9095번
https://www.acmicpc.net/problem/9095
*/

//algorithm: Dynamic_Programming

#include <stdio.h>

int main(void) {
	int dp[100000] = {0,1,2,4,};
	for(int i = 4; i<=100000; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	int n;
	scanf("%d",&n);
	while(n--){
		int k;
		scanf("%d",&k);
		printf("%d\n",dp[k]);
	}
	return 0;
}
