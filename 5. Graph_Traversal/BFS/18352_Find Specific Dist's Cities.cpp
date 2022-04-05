/*
백준 18352번
https://www.acmicpc.net/problem/18352
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 300001

using namespace std;

struct NODE {
	int node;
	int cost;
};

int n, m, k, x;
queue<NODE> q;
vector<NODE> map[MAX_SIZE];
bool can_arrive[MAX_SIZE];
bool visited[MAX_SIZE];

void input(void) {
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back({ b,0 });
	}
}

void BFS(NODE start) {
	memset(visited, false, sizeof(visited));
	memset(can_arrive, false, sizeof(can_arrive));
	q.push(start);
	int ans = 0;
	bool flag = false;
	while (!q.empty()) {
		NODE top = q.front();
		q.pop();
		if (visited[top.node]) continue;
		visited[top.node] = true;
		if (top.cost == k) {
			can_arrive[top.node] = true;
			flag = true;
		}
		if (top.cost > k) break;
		for (int i = 0; i < map[top.node].size(); i++) {
			NODE arrival = map[top.node][i];
			if (visited[arrival.node]) continue;
			q.push({ arrival.node,top.cost + 1 });
		}
	}
	if (flag) {
		for (int i = 1; i <= n; i++) {
			if (can_arrive[i]) {
				cout << i << '\n';
			}
		}
	}
	else cout << "-1";
	return;
}

int main(void) {
	input();
	BFS({ x,0 });
	return 0;
}
