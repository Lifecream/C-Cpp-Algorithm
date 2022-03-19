/*
백준 1162번
https://www.acmicpc.net/problem/1162
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 10001
#define PAVE_SIZE 21
#define INF 9223372036854775806

using namespace std;

struct CMP {
	int node;
	long long cost;
	int pave_counter;
	bool operator()(CMP a, CMP b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

priority_queue <CMP, vector<CMP>, CMP> pq;
vector<CMP> map[MAX_SIZE];
CMP start = { 1,0,0 };
bool visited[MAX_SIZE][PAVE_SIZE];
long long dist[MAX_SIZE][PAVE_SIZE];
int n, m, k;

void set_default(void) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < PAVE_SIZE; j++) {
			if (i == 1) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	memset(visited, false, sizeof(visited));
	return;
}

void dist_check(void) {
	for (int i = 1; i <= n; i++) {
		cout << "dist[" << i << "][ ";
		for (int j = 1; j <= k; j++) {
			if (dist[i][j] >= INF) cout << "INF ";
			else cout << dist[i][j] << ' ';
		}
		cout << "]\n";
	}
	return;
}

long long Dijkstra(CMP s) { 
	long long ans = 0;
	set_default();
	pq.push(s);
	int cnt = n;
	while (!pq.empty()) {
		CMP top = pq.top();
		if (visited[top.node][top.pave_counter]) {
			pq.pop();
			continue;
		}
		if (top.node == n) {
			ans = top.cost;
			break;
		}
		visited[top.node][top.pave_counter] = true;
		for (int i = 0; i < map[top.node].size(); i++) {
			CMP arrival = map[top.node][i];
			if (visited[arrival.node][top.pave_counter]) continue;
			dist[arrival.node][top.pave_counter] = min(dist[arrival.node][top.pave_counter], top.cost + arrival.cost);
			CMP temp = { arrival.node,top.cost + arrival.cost,top.pave_counter };
			pq.push(temp);
			if (top.pave_counter < k) {
				if (!visited[arrival.node][top.pave_counter + 1]) {
					dist[arrival.node][top.pave_counter + 1] = min(dist[arrival.node][top.pave_counter + 1], top.cost);
					temp = { arrival.node,top.cost,top.pave_counter + 1 };
					pq.push(temp);
				}
			}
		}
		pq.pop();
	}
	//dist_check();
	return ans;
}

void input(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		CMP temp = { b,d,0 };
		map[a].push_back(temp);
		temp = { a,d,0 };
		map[b].push_back(temp);
	}
	return;
}
 
int main(void) {
	input();
	cout <<	Dijkstra(start);
	return 0;
}
