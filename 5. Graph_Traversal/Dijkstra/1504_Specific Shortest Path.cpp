/*
백준 1504번
https://www.acmicpc.net/problem/1504
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 20001
#define INF 987654321

using namespace std;

struct CMP {
	int node;
	int cost;
	bool operator()(CMP a, CMP b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

priority_queue <CMP, vector<CMP>, CMP> pq;
int n, e, v1, v2;
int ans = -1;
vector<CMP> map[MAX_SIZE];
int dist1[MAX_SIZE];
int distv1[MAX_SIZE];
int distv2[MAX_SIZE];
bool visited[MAX_SIZE];

void input(void) {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
}

void dist_check(int* d) {
	cout << "dist[";
	for (int i = 1; i <= n; i++) {
		if (d[i] >= INF) cout << " INF";
		else cout << ' ' << d[i];
	}
	cout << " ]\n";
}

void Dijkstra(CMP s,int* dist) {
	for (int i = 0; i < MAX_SIZE; i++) dist[i] = INF;
	dist[s.node] = 0;
	memset(visited, false, sizeof(visited));
	//dist_check(dist);
	int cnt = n;
	pq.push(s);
	while (!pq.empty()) {
		CMP top = pq.top();
		pq.pop();
		if (visited[top.node]) continue;
		visited[top.node] = true;
		cnt--;
		if (cnt == 0) break;
		for (int i = 0; i < map[top.node].size(); i++) {
			CMP arrival = map[top.node][i];
			if (visited[arrival.node]) continue;
			dist[arrival.node] = min(dist[arrival.node], top.cost + arrival.cost);
			CMP temp = { arrival.node,top.cost + arrival.cost };
			pq.push(temp);
		}
	}
	//dist_check(dist);
}

void Solution(void) {
	Dijkstra({ 1,0 }, dist1);
	Dijkstra({ v1,0 }, distv1);
	Dijkstra({ v2,0 }, distv2);
	int way1 = INF;
	int way2 = INF;
	if (dist1[v1] != INF && distv1[v2] != INF && distv2[n] != INF) way1 = dist1[v1] + distv1[v2] + distv2[n];
	if (dist1[v2] != INF && distv2[v1] != INF && distv1[n] != INF) way2 = dist1[v2] + distv2[v1] + distv1[n];
	ans = min(way1, way2);
	if (ans >= INF) ans = -1;
}

int main(void) {
	input();
	Solution();
	cout << ans;
	return 0;
}
