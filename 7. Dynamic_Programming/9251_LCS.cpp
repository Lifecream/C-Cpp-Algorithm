/*
백준 9251번
https://www.acmicpc.net/problem/9251
*/

//algorithm: Dynamic_Programming

#include <iostream>
#include <cstring>

using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int dp[1001][1001] = {0,};

int main(void) {
    char a[1001];
    char b[1001];    
    cin >> a >> b;
    for(int i = 1; i<=strlen(a); i++){
        for(int j = 1; j<=strlen(b); j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    printf("%d",dp[strlen(a)][strlen(b)]);
    return 0;
}
