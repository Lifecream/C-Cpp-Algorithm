/*
백준 7569번
https://www.acmicpc.net/problem/7569
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
	int z;
	int day;
};

queue<LOCATION> q;
int map[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int n, m,h;
int cnt = 0;

void input(void) {
	memset(map, -1, sizeof(map));
	memset(visited, false, sizeof(visited));
	cin >> m >> n >> h;
	for (int l = 1; l <= h; l++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> map[i][j][l];
				if (map[i][j][l] == 1) {
					q.push({ i,j,l,0 });
				}
				if (map[i][j][l] == 0) {
					cnt++;
				}

			}
		}
	}
}

int bfs(void) {
	LOCATION top;
	while (!q.empty()) {
		top = q.front();
		visited[top.x][top.y][top.z] = true;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			int nz = top.z + dz[i];
			if (nx == 0 || nx > n || ny == 0 || ny > m || nz == 0 || nz > h) continue;
			if (visited[nx][ny][nz]) continue;
			if (map[nx][ny][nz] == -1 || map[nx][ny][nz] == 1) continue;
			q.push({ nx ,ny,nz,top.day+1});
			visited[top.x][top.y][top.z] = true;
			map[nx][ny][nz] = 1;
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
