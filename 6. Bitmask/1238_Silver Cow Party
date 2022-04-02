/*
백준 1238번
https://www.acmicpc.net/problem/1238
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 1001
#define INF 2000000000

using namespace std;

struct CMP {
	int node;
	int cost;
	bool operator()(CMP a, CMP b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

int n, m, x;
vector<CMP> map[MAX_SIZE];
priority_queue<CMP, vector<CMP>, CMP> pq;
int first_dist[MAX_SIZE] = { 0, };
int second_dist[MAX_SIZE] = { 0, };
bool visited[MAX_SIZE];

void make_pq_empty(void) {
	while (!pq.empty()) pq.pop();
	return;
}

void input(void) {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		map[a].push_back({ b,d });
	}
}

void check_dist(int* dist) {
	cout << "dist[ ";
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	cout << "]\n";
}

void first_Dijkstra(int start) {
	for (int i = 1; i <= n; i++) {
		if (i == start) continue;
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < map[i].size(); j++) {
			pq.push(map[i][j]);
		}
		while (!pq.empty()) {
			CMP top = pq.top();
			pq.pop();
			if (visited[top.node]) continue;
			visited[top.node] = true;
			if (top.node == start) {
				first_dist[i] = top.cost;
				make_pq_empty();
				break;
			}
			for (int j = 0; j < map[top.node].size(); j++) {
				CMP arrival = map[top.node][j];
				if (visited[arrival.node]) continue;
				pq.push({ arrival.node, top.cost + arrival.cost });
			}
		}
	}
	//check_dist(first_dist);
}

void second_Dijkstra(int start) {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i <= n; i++) {
		second_dist[i] = INF;
	}
	second_dist[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty()) {
		CMP top = pq.top();
		pq.pop();
		if (visited[top.node]) continue;
		visited[top.node] = true;
		for (int j = 0; j < map[top.node].size(); j++) {
			CMP arrival = map[top.node][j];
			if (visited[arrival.node]) continue;
			second_dist[arrival.node] = min(second_dist[arrival.node], second_dist[top.node] + arrival.cost);
			pq.push({ arrival.node, top.cost + arrival.cost });
		}
	}
	//check_dist(second_dist);
}

int Dijkstra(void) {
	first_Dijkstra(x);
	second_Dijkstra(x);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp = first_dist[i] + second_dist[i];
		if (ans < temp) ans = temp;
	}
	return ans;
}

int main(void) {
	input();
	cout << Dijkstra();
	return 0;
}
