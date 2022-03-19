/*
백준 4485번
https://www.acmicpc.net/problem/4485
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 126

using namespace std;

struct LOCATION {
	int x;
	int y;
	int cost;
	bool operator()(LOCATION a, LOCATION b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

priority_queue<LOCATION, vector<LOCATION>, LOCATION> pq;
int n;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void set_default(void) {
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	while (!pq.empty()) pq.pop();
}

int bfs(LOCATION start) {
	pq.push(start);
	while (!pq.empty()) {
		LOCATION top = pq.top();
		pq.pop();
		if (visited[top.x][top.y]) continue;
		if (top.x == n && top.y == n) return top.cost;
		visited[top.x][top.y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
			pq.push({ nx,ny,top.cost + map[nx][ny] });
		}
	}
}

int main(void) {
	int tc = 0;
	while(++tc){
		set_default();
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
			}
		}
		cout << "Problem " << tc << ": " << bfs({1,1,map[1][1]}) << '\n';
	}
	return 0;
}
