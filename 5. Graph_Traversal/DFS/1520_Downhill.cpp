/*
백준 1520번
https://www.acmicpc.net/problem/1520
*/

//algorithm: DFS

#include <iostream>
#include <stack>

using namespace std;

int map[501][501] = {0,};
int dp[501][501] = {0,};
int p = 0;
int w,h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int a, int b){
	if(a == h && b == w){
		return 1;
	}
	if(dp[a][b] != -1) return dp[a][b];
	dp[a][b] = 0;
	for(int i = 0; i<4; i++){
		if(a+dx[i] != 0 && a+dx[i] <= h && b+dy[i] != 0 && b+dy[i] <= w){
			if(map[a][b] > map[a+dx[i]][b+dy[i]]) {
				dp[a][b] += dfs(a+dx[i],b+dy[i]);
			}
		}
	}
	return dp[a][b];
}

int main(void) {
	cin >> h >> w;
	for(int i = 1; i<=h; i++){
		for(int j = 1; j<=w; j++){
			dp[i][j] = -1;
			cin >> map[i][j];
		}
	}
	dfs(1,1);
	cout << dp[1][1];
    return 0;
}
