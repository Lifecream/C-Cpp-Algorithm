/*
백준 2665번
https://www.acmicpc.net/problem/2665
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 1001
#define INF 987654321

using namespace std;

struct NODE {
	int x;
	int y;
	int cost;
	bool operator()(NODE a, NODE b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

int n;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
priority_queue<NODE, vector<NODE>, NODE> pq;

void Print_map(void) {
	cout << "\n[DEBUG]\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void input(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char a;
			cin >> a;
			if (a == '1') map[i][j] = true;
			else map[i][j] = false;
		}
	}
}

int Dijkstra(void) {
	int ans = 0;
	memset(visited, false, sizeof(visited));
	pq.push({ 1,1,0 });
	while (!pq.empty()) {
		NODE top = pq.top();
		pq.pop();
		if (visited[top.x][top.y]) continue;
		if (top.x == n && top.y == n) {
			ans = top.cost;
			break;
		}
		visited[top.x][top.y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if (nx > n || nx == 0 || ny > n || ny == 0) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny]) pq.push({ nx,ny,top.cost });
			else pq.push({ nx,ny,top.cost + 1 });
		}
	}
	return ans;
}

int main(void) {
	input();
	cout << Dijkstra();
	return 0;
}
