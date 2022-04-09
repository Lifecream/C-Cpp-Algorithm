/*
백준 10217번
https://www.acmicpc.net/problem/10217
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 101
#define COST_SIZE 10001
#define INF 987654321

using namespace std;

struct NODE {
	int node;
	int cost;
	int time;
	bool operator()(NODE a, NODE b) {
		if (a.time > b.time) return true;
		else return false;
	}
};

int T, n, m, k;
int dist[MAX_SIZE][COST_SIZE];

void Print_NODE(NODE temp) {
	cout << "TOP[ " << temp.node << ' ' << temp.cost << ' ' << temp.time << "]\n";
}

int Dijkstra(vector<NODE>* map) {
	int ans = INF;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dist[i][j] = INF;
		}
	}
	dist[1][0] = 0;
	priority_queue<NODE, vector<NODE>, NODE> pq;
	pq.push({ 1,0,0 });
	while (!pq.empty()) {
		NODE top = pq.top();
		//Print_NODE(top);
		pq.pop();
		if (top.time > dist[top.node][top.cost]) continue;
		for (int i = 0; i < map[top.node].size(); i++) {
			NODE arrival = map[top.node][i];
			if (arrival.cost + top.cost > m) continue;
			if (top.time + arrival.time < dist[arrival.node][arrival.cost + top.cost]) {
				for (int j = arrival.cost + top.cost + 1; j <= m; j++) {
					if (dist[arrival.node][j] <= top.time + arrival.time) break;
					dist[arrival.node][j] = arrival.time + top.time;
				}
				dist[arrival.node][arrival.cost + top.cost] = top.time + arrival.time;
				//cout << "PUSH: " << top.node << " -> " << arrival.node << ' ' << top.cost << '+' << arrival.cost << ' ' << top.time << '+' << arrival.time << '\n';
				pq.push({ arrival.node, arrival.cost + top.cost, arrival.time + top.time });
			}
		}
	}
	return dist[n][m];
}

int main(void) {
	cin >> T;
	while (T--) {
		cin >> n >> m >> k;
		vector<NODE> graph[MAX_SIZE];
		for (int i = 0; i < k; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d; //u -> v / cost: c time: d
			graph[u].push_back({ v,c,d });
		}
		int ans = Dijkstra(graph);
		if (ans >= INF) cout << "Poor KCM" << '\n';
		else cout << ans << '\n';
	}
	return 0;
}
