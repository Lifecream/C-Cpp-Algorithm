/*
백준 1311번
https://www.acmicpc.net/problem/1311
*/

//algorithm: Bitmask

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define VISIT 1 << 20
#define MAX_SIZE 21
#define INF 2000000000

using namespace std;

int n;
int work[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][VISIT];

void input(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> work[i][j];
		}
	}
}

int Dynamic_Programming(int index, int visited) {
	if (visited == (1 << n) - 1) return 0;
	if (dp[index][visited]) return dp[index][visited];
	dp[index][visited] = INF;
	for (int i = 0; i < n; i++) {
		if (visited & (1 << i)) continue;
		dp[index][visited] = min(dp[index][visited], Dynamic_Programming(index + 1, visited + (1 << i)) + work[index][i]);
	}
	return dp[index][visited];
}

int main(void) {
	input();
	memset(dp, 0, sizeof(dp));
	cout << Dynamic_Programming(0, 0);
	return 0;
}
