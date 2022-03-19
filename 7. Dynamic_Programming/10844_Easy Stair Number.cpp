/*
백준 10844번
https://www.acmicpc.net/problem/10844
*/

//algorithm: Dynamic_Programming

#include <iostream>
#include <algorithm>
#include <cstring>
#define DIV 1000000000
using namespace std;

int dp[101][11] = {0,};

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	dp[1][0] = 0;
	dp[1][10] = 9;
	for (int i = 2; i <= 100; i++) {
		dp[i][10] = 0;
		dp[i][0] = dp[i-1][1];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % DIV;
		}
		dp[i][9] = dp[i-1][8];
		for (int j = 0; j <= 9; j++) {
			dp[i][10] += dp[i][j];
			dp[i][10] %= DIV;
		}
	}
	cout << dp[n][10];
	return 0;
}
