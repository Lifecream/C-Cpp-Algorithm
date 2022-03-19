/*
백준 7576번
https://www.acmicpc.net/problem/7576
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX_SIZE 1001

using namespace std;

struct LOCATION {
	int x;
	int y;
	int day;
};

queue<LOCATION> q;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
int cnt = 0;

void input(void) {
	memset(map, -1, sizeof(map));
	memset(visited, false, sizeof(visited));
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j,0});
			}
			if (map[i][j] == 0) {
				cnt++;
			}
		}
	}
}

int bfs(void) {
	LOCATION top;
	while (!q.empty()) {
		top = q.front();
		visited[top.x][top.y] = true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if (nx == 0 || nx > n || ny == 0 || ny > m) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == -1 || map[nx][ny] == 1) continue;
			q.push({ nx ,ny,top.day+1});
			visited[top.x][top.y] = true;
			map[nx][ny] = 1;
			cnt--;
		}
	}
	if (!cnt) return top.day;
	else return -1;
}

int main(void) {
	input();
	cout << bfs();
	return 0;
}
