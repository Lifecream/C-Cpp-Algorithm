/*
백준 1699번
https://www.acmicpc.net/problem/1699
*/

//algorithm: Dynamic_Programming

#include <stdio.h>
#include <math.h>

int dp[100001] = {0,};

int main(void){
	int n;
	scanf("%d",&n);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i<=n; i++){
        if(i == pow((int)sqrt(i),2)){
            dp[i] = 1;
            continue;
        }
        int min = -1;
        for(int j = 1; j<=i/2; j++){
            if(min == -1 || min > dp[j] + dp[i-j]){
                min = dp[j] + dp[i-j];
            }
        }
        dp[i] = min;
    }
    printf("%d",dp[n]);
    return 0;
}
