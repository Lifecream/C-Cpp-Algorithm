/*
백준 9370번
https://www.acmicpc.net/problem/9370
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 2001
#define INF 987654321

using namespace std;

struct CMP {
	int node;
	int cost;
	int passed;
	bool operator()(CMP a, CMP b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

int T, n, m, t, s, g, h;
vector<CMP> graph[MAX_SIZE];
bool visited[MAX_SIZE][2];
bool condidate[MAX_SIZE];

void check_dist(int (*arr)[2]) {
	cout << "[DEBUG]: \ndist[ ";
	for (int i = 1; i <= n; i++) {
		if (arr[i][0] >= INF) cout << "INF ";
		else cout << arr[i][0] << ' ';
	}
	cout << "\n     ";
	for (int i = 1; i <= n; i++) {
		if (arr[i][1] >= INF) cout << "INF ";
		else cout << arr[i][1] << ' ';
	}
	cout << "]\n";
}

void Dijkstra(CMP start, vector<CMP>* map) {
	int dist[MAX_SIZE][2];
	for (int i = 1; i <= n; i++) {
		dist[i][0] = INF;
		dist[i][1] = INF;
	}
	dist[s][0] = 0;
	memset(visited, false, sizeof(visited));
	priority_queue<CMP, vector<CMP>, CMP> pq;
	pq.push(start);
	while (!pq.empty()) {
		CMP top = pq.top();
		pq.pop();
		if (visited[top.node][top.passed]) continue;
		visited[top.node][top.passed] = true;
		for (int i = 0; i < map[top.node].size(); i++) {
			CMP arrival = map[top.node][i];
			if ((top.node == g && arrival.node == h) || (top.node == h && arrival.node == g) || top.passed == 1) arrival.passed = 1;
			if (visited[arrival.node][arrival.passed]) continue;
			dist[arrival.node][arrival.passed] = min(dist[arrival.node][arrival.passed], top.cost + arrival.cost);
			pq.push({ arrival.node,arrival.cost + top.cost,arrival.passed });
		}
	}
	//check_dist(dist);
	for (int i = 1; i <= n; i++) {
		if (condidate[i] && dist[i][0] >= dist[i][1] && dist[i][1] < INF) {
			cout << i << '\n';
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		vector<CMP> graph[MAX_SIZE];
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			graph[a].push_back({ b,c,0 });
			graph[b].push_back({ a,c,0 });
		}
		memset(condidate, false, sizeof(condidate));
		for (int i = 0; i < t; i++) {
			int a;
			cin >> a;
			condidate[a] = true;
		}
		Dijkstra({ s,0,0 }, graph);
	}
	return 0;
}
