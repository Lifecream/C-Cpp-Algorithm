/*
백준 1956번
https://www.acmicpc.net/problem/1956
*/

//algorithm: Floyd-Warshall

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 401
#define INF 1 << 30

using namespace std;

struct NODE {
	int node;
	int cost;
	bool operator()(NODE a, NODE b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

int v, e;
int dist[MAX_SIZE][MAX_SIZE] = { 0, };
vector<NODE> graph[MAX_SIZE];

void DEBUG(void) {
	cout << "[DEBUG]\n";
	for (int i = 1; i <= v; i++) {
		cout << "[ ";
		for (int j = 1; j <= v; j++) {
			if (dist[i][j] >= INF) cout << "INF ";
			else cout << dist[i][j] << ' ';
		}
		cout << "]\n";
	}
}

void input(void) {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
}

int Floyd_Warshall(void) {
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) dist[i][j] = 0;
			else if (dist[i][j] != 0) continue;
			else dist[i][j] = INF;
		}
	}

	for (int second = 1; second <= v; second++) {
		for (int first = 1; first <= v; first++) {
			if (first == second) continue;
			for (int third = 1; third <= v; third++) {
				if (first == third || second == third) continue;
				if (dist[first][second] == INF || dist[second][third] == INF) continue;
				dist[first][third] = min(dist[first][third], dist[first][second] + dist[second][third]);
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			if (dist[i][j] == INF || dist[j][i] == INF) continue;
			ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}
	if (ans == INF) ans = -1;
	return ans;
}

int main(void) {
	input();
	cout << Floyd_Warshall();
	return 0;
}
