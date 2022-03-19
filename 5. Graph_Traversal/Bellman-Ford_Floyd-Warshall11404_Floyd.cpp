/*
백준 11404번
https://www.acmicpc.net/problem/11404
*/

//algorithm: Floyd-Warshall

#include <iostream>
#include <algorithm>
#define INF 1000000000
#define MAX_SIZE 101

using namespace std;

int v, e;
int dist[MAX_SIZE][MAX_SIZE];

void set_default(void) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else dist[i][j] = INF;
		}
	}
}

void output(void) {
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (dist[i][j] == INF) cout << "0 ";
			else cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input(void) {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
}

void Floyd_Warshall(void) {
	for(int middle = 1; middle <= v; middle++){
		for (int from = 1; from <= v; from++) {
			for (int to = 1; to <= v; to++) {
				dist[from][to] = min(dist[from][to], dist[from][middle] + dist[middle][to]);
			}
		}
	}
}

int main(void) {
	set_default();
	input();
	Floyd_Warshall();
	output();
	return 0;
}
