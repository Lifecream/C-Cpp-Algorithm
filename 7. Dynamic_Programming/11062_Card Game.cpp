/*
백준 11062번
https://www.acmicpc.net/problem/11062
*/

//algorithm: Dynamic_Programming

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1002][1002] = {0,};
int card[1002] = {0,};
int sum[1002] = {0,};

int p(int left,int right){
	if(dp[left][right]) return dp[left][right];
	if(left == right) return card[left];
	int s = sum[right] - sum[left-1];
	dp[left][right] = max(s-p(left+1,right),s-p(left,right-1));
	return dp[left][right];
}

int main(void){
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	for(int i = 1; i<=n; i++){
    		cin >> card[i];
			sum[i] = sum[i-1] + card[i];
		}
    	cout << p(1,n) << '\n';
    	memset(card,0,sizeof(card));
    	memset(dp,0,sizeof(dp));
	}
    return 0;
}
