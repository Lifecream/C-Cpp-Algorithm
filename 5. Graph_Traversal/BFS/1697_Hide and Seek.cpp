/*
백준 1697번
https://www.acmicpc.net/problem/1697
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX_SIZE 200001

using namespace std;

struct PLACE {
	int x;
	int day;
};

int n, m;
queue<PLACE> q;
bool visited[MAX_SIZE];

void set_default(void) {
	memset(visited, false, sizeof(visited));
	return;
}

void input(void) {
	cin >> n >> m;
	return;
}

int bfs(PLACE s) {
	q.push(s);
	visited[s.x] = true;
	PLACE top;
	while (!q.empty()) {
		top = q.front();
		if (top.x == m) break;
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = 0;
			if (i == 0) nx = top.x + 1;
			else if (i == 1) nx = top.x - 1;
			else nx = top.x * 2;
			if (nx < 0 || nx > 200001) continue;
			if (visited[nx]) continue;
			q.push({ nx ,top.day + 1 });
			visited[nx] = true;
		}
	}
	return top.day;
}

int main(void) {
	set_default();
	input();
	cout << bfs({n,0});
	return 0;
}
