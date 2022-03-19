/*
백준 1229번
https://www.acmicpc.net/problem/1229
*/

//algorithm: Dynamic_Programming

#include <iostream>

using namespace std;

unsigned long long Big_Bang[10000] = {0,};
int dp[1000001] = {0,};

int main(void){
	int n;
	cin >> n;
	Big_Bang[0] = 1;
	dp[1] = 1;
	for(int i = 1;; i++){
		Big_Bang[i] = Big_Bang[i-1] + 4*i + 1;
		if(Big_Bang[i] > n) break;
		dp[Big_Bang[i]] = 1;
	}
	
	for(int i = 2; i<=n; i++){
		if(dp[i] != 0) continue;
		int min = -1;
		for(int j = 0; Big_Bang[j]<i; j++){
			int temp = dp[Big_Bang[j]] + dp[i-Big_Bang[j]];
			if(min == -1 || min > temp) min = temp;
		}
		dp[i] = min;
	}
	cout << dp[n];
	return 0;
}
