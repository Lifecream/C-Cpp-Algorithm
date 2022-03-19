/*
백준 1915번
https://www.acmicpc.net/problem/1915
*/

//algorithm: Dynamic_Programming

#include <iostream>
#include <algorithm>

using namespace std;
int map[1002][1002] = {0,};
int n,m;

int main(void) {
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			char a;
			cin >> a;
			map[i][j] = a-48;
		}
	}
	int b = 0;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(map[i][j] != 0) map[i][j] = min(map[i-1][j-1],min(map[i][j-1],map[i-1][j]))+1;
			if(b < map[i][j]) b = map[i][j];
		}
	}
	cout << b * b;
	return 0;
}
