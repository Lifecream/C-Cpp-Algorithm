/*
백준 7562번
https://www.acmicpc.net/problem/7562
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX_SIZE 301

using namespace std;

struct LOCATION {
	int x;
	int y;
	int cnt;
};

queue<LOCATION> q;
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void set_default(void) {
	memset(visited, false, sizeof(visited));
	while (!q.empty()) q.pop();
	return;
}

int bfs(LOCATION start, LOCATION arrival,int map_size) {
	LOCATION top;
	q.push(start);
	while (!q.empty()) {
		top = q.front();
		visited[top.x][top.y] = true;
		q.pop();
		if (top.x == arrival.x && top.y == arrival.y) break;
		for (int i = 0; i < 8; i++) {
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if (nx < 0 || nx >= map_size || ny < 0 || ny >= map_size) continue;
			if (visited[nx][ny]) continue;
			q.push({ nx ,ny,top.cnt + 1 });
			visited[nx][ny] = true;
		}
	}
	return top.cnt;
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		set_default();
		int s;
		cin >> s;
		LOCATION a = {0,}, b = {0,};
		cin >> a.x >> a.y >> b.x >> b.y;
		cout << bfs(a, b, s) << endl;
	}
	return 0;
}
