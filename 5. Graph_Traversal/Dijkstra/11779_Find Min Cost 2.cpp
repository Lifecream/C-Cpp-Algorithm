/*
백준 11779번
https://www.acmicpc.net/problem/11779
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
	int node;
	int cost;
	vector<int> v;
	bool operator()(NODE a, NODE b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

int n, m, v1, v2;
bool visited[MAX_SIZE];
priority_queue<NODE, vector<NODE>, NODE> pq;
vector<NODE> map[MAX_SIZE];

void input(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}
	cin >> v1 >> v2;
}

void Print_ans(NODE temp) {
	cout << temp.cost << '\n' << temp.v.size() << '\n';
	for (int i = 0; i < temp.v.size(); i++) {
		cout << temp.v[i] << ' ';
	}
}

void Dijkstra(NODE start) {
	memset(visited, false, sizeof(visited));
	pq.push(start);
	while (!pq.empty()) {
		NODE top = pq.top();
		pq.pop();
		top.v.push_back(top.node);
		if (visited[top.node]) continue;
		if (top.node == v2) {
			Print_ans(top);
			break;
		}
		visited[top.node] = true;
		for (int i = 0; i < map[top.node].size(); i++) {
			NODE arrival = map[top.node][i];
			if (visited[arrival.node]) continue;
			pq.push({ arrival.node,top.cost + arrival.cost,top.v });
		}
	}
	return;
}

int main(void) {
	input();
	Dijkstra({ v1,0, });
	return 0;
}
