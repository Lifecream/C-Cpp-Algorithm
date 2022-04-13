/*
백준 1932번
https://www.acmicpc.net/problem/1932
*/

//algorithm: Dynamic_Programming

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_SIZE 501

using namespace std;

int n;
int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) dp[n][i] = map[n][i];
	for (int i = n-1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + map[i][j];
		}
	}
	cout << dp[1][1];
	return 0;
}
