/*
백준 2178번
https://www.acmicpc.net/problem/2178
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX_SIZE 101

using namespace std;

struct LOCATION {
	int x;
	int y;
	int counter;
};

queue<LOCATION> q;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

void input(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
}

int bfs(LOCATION a) {
	int min = -1;
	q.push(a);
	memset(visited, false, sizeof(visited));
	visited[1][1] = true;
	while (!q.empty()) {
		LOCATION top = q.front();
		q.pop();
		if (top.x == n && top.y == m) {
			if (min == -1 || min > top.counter) {
				min = top.counter;
				continue;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if (nx == 0 || nx > n || ny == 0 || ny > m) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == '0') continue;
			q.push({ nx ,ny ,top.counter + 1 });
			visited[nx][ny] = true;
		}
	}
	return min;
}

int main(void) {
	input();
	cout << bfs({1,1,1});
	return 0;
}
