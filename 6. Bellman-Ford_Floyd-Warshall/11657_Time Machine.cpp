/*
백준 11657
https://www.acmicpc.net/problem/11657
*/

//algorithm: Bellman-Ford

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define INF 2000000000
#define MAX_SIZE 501

using namespace std;

struct WAY {
	long long from;
	long long to;
	long long cost;
};

int n, m;
vector<WAY> map;
long long dist[MAX_SIZE];

void set_default(void) {
	for (int i = 0; i < MAX_SIZE; i++) dist[i] = INF;
	dist[1] = 0;
}

void input(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		map.push_back({ a,b,c });
	}
}

void output(void) {
	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF) cout << "-1\n";
		else cout << dist[i] << '\n';
	}
}

void edge_relaxation(long long* arr) {
	for (int j = 0; j < map.size(); j++) {
		if (arr[map[j].from] == INF) continue;
		arr[map[j].to] = min(arr[map[j].to], arr[map[j].from] + map[j].cost);
	}
}

bool check_negative_cycle(void) {
	long long temp[MAX_SIZE];
	memcpy(temp, dist, sizeof(temp));
	edge_relaxation(temp);
	for (int i = 1; i <= n; i++) {
		if (temp[i] == dist[i]) continue;
		return true;
	}
	return false;
}

void Bellman_Ford(void) {
	for (int i = 1; i <= n-1; i++) edge_relaxation(dist);
	if (check_negative_cycle()) cout << "-1";
	else output();
}

int main(void) {
	set_default();
	input();
	Bellman_Ford();
	return 0;
}
