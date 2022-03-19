/*
백준 1904번
https://www.acmicpc.net/problem/1904
*/

//algorithm: Dynamic_Programming

#include <iostream>
#define DIV 15746

using namespace std;

int dp[1000001];

int main(void){
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i<=1000000; i++){
		dp[i] = (dp[i-1] % DIV + dp[i-2] % DIV) % DIV;
	}
	int n;
	cin >> n;
	cout<< dp[n];
	return 0;
}
