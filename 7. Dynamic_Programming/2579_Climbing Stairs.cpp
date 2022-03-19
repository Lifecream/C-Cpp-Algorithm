/*
백준 2579번
https://www.acmicpc.net/problem/2579
*/

//algorithm: Dynamic_Programming

#include <iostream>
#include <algorithm>
#define MAX_SIZE 301

using namespace std;

int main(void) {
	int arr[MAX_SIZE] = {0,};
	int dp[MAX_SIZE] = { 0, };
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1]);
	}
	cout << dp[n];
	return 0;
}
