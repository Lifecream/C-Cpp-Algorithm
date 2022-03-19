/*
백준 1261번
https://www.acmicpc.net/problem/1261
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 101

using namespace std;

struct LOCATION {
	int x;
	int y;
	int counter;
	bool operator()(LOCATION a, LOCATION b) {
		if (a.counter > b.counter) return true;
		else return false;
	}
};

priority_queue<LOCATION, vector<LOCATION>, LOCATION> pq;
int n, m;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
LOCATION start = { 1,1,0 };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(LOCATION s) {
	int ans;
	memset(visited, false, sizeof(visited));
	pq.push(s);
	while (!pq.empty()) {
		LOCATION top = pq.top();
		if (visited[top.x][top.y]) {
			pq.pop();
			continue;
		}
		if (top.x == n && top.y == m) {
			ans = top.counter;
			break;
		}
		visited[top.x][top.y] = true;
		for (int i = 0; i < 4; i++) {
			if (top.x + dx[i] == 0 || top.x + dx[i] > n || top.y + dy[i] == 0 || top.y + dy[i] > m) continue;
			if (visited[top.x + dx[i]][top.y + dy[i]]) continue;
			LOCATION temp = { top.x + dx[i],top.y + dy[i],top.counter + map[top.x + dx[i]][top.y + dy[i]] - 48 };
			pq.push(temp);
		}
		pq.pop();
	}
	return ans;
}

void input(void) {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
}

int main(void) {
	input();
	cout << bfs(start);
	return 0;
}
