/*
백준 2206번
https://www.acmicpc.net/problem/2206
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX_SIZE 1001

using namespace std;

struct LOCATION {
	int x;
	int y;
	int cnt;
	bool is_wall_broken;
};

queue<LOCATION> q;
int n, m;
char map[MAX_SIZE][MAX_SIZE] = {0,};
bool visited[MAX_SIZE][MAX_SIZE][2];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void set_default(void) {
	memset(visited, false, sizeof(visited));
	visited[1][1][0] = true;
	while (!q.empty()) q.pop();
	return;
}

void input(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
}

void printq(void) {
	int temp = q.size();
	cout << "Queue[ ";
	for (int i = 0; i < temp; i++) {
		cout << '{' << q.front().x << ',' << q.front().y << ',' << q.front().is_wall_broken << "} , ";
		q.push(q.front());
		q.pop();
	}
	cout << "]\n";
}

int bfs(LOCATION start, LOCATION arrival) {
	LOCATION top;
	q.push(start);
	while (!q.empty()) {
		top = q.front();
		//printq();
		q.pop();
		if (top.x == arrival.x && top.y == arrival.y) return top.cnt;
		for (int i = 0; i < 4; i++) {
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (!visited[nx][ny][top.is_wall_broken] && map[nx][ny] == '0') {
				q.push({ nx ,ny,top.cnt + 1,top.is_wall_broken });
				visited[nx][ny][top.is_wall_broken] = true;
			}
			else if (!visited[nx][ny][1] && !top.is_wall_broken && map[nx][ny] == '1') {
				q.push({ nx ,ny,top.cnt + 1,true });
				visited[nx][ny][1] = true;
			}
			else continue;
		}
	}
	return -1;
}

int main(void) {
	set_default();
	input();
	cout << bfs({ 1,1,1,false }, { n,m,0,false });
	return 0;
}
