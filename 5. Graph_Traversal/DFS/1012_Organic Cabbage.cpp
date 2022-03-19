/*
백준 1012번
https://www.acmicpc.net/problem/1012
*/

//algorithm: DFS

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char map[51][51] = { 0, };
int p = 0;
int n, m, k;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void printmap(void) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	return;
}

void dfs(int a, int b) {
	map[a][b] = '0';
	for (int i = 0; i < 4; i++) {
		if (map[a + dx[i]][b + dy[i]] == '1') dfs(a + dx[i], b + dy[i]);
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		p = 0;
		memset(map, '0', sizeof(map));
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[x + 1][y + 1] = '1';
		}
		//cout << '\n';
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == '1') {
					dfs(i, j);
					//printmap();
					p++;
				}
			}
		}
		cout << p << '\n';
	}
	return 0;
}
