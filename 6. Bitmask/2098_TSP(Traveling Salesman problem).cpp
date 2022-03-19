/*
백준 2098번
https://www.acmicpc.net/problem/2098
*/

//algorithm: Bitmask

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
#define MAX_SIZE 17
#define INF 2000000000

using namespace std;

int n;
int ans = INF;
int way[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][1 << 17];

void input(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> way[i][j];
			if (( i != j ) && (way[i][j] == 0)) way[i][j] = INF;
		}
	}
	memset(dist, -1, sizeof(dist));
}

int DFS(int start, int index, int visit) {
	if (visit == (1 << n) - 1) return way[index][start];
	if (dist[index][visit] != -1) return dist[index][visit];
	dist[index][visit] = INF;
	//printf("dist[%d][", index), cout << bitset<4>(visit) << "] = " << dist[index][visit] << endl;
	for (int i = 0; i < n; i++) {
		int temp = 1 << i;
		if ((visit & temp) || i == index || way[index][i] == INF) continue;
		dist[index][visit] = min(dist[index][visit], DFS(start, i, visit + temp) + way[index][i]);
	}
	return dist[index][visit];
}

int main(void) {
	input();
	cout << DFS(0, 0, 1);
	return 0;
}
