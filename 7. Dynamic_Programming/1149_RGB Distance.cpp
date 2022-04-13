/*
백준 1149번
https://www.acmicpc.net/problem/1149
*/

//algorithm: Dynamic_Programming

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX_SIZE 1001

using namespace std;

int n;
int cost[MAX_SIZE][3]; //cost[][0]: R / cost[][1]: G / cost[][2]: B
int dp[MAX_SIZE][3];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
	return 0;
}
