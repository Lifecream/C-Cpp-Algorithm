/*
백준 11724번
https://www.acmicpc.net/problem/11724
*/

//algorithm: DFS

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_SIZE 1001

using namespace std;

int n, m;
bool connected[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int cnt = 0;

void set_default(void) {
	memset(connected, false, sizeof(connected));
	memset(visited, false, sizeof(visited));
	return;
}

void input(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connected[a][b] = true;
		connected[b][a] = true;
	}
}

void DFS(int index) {
	visited[index] = true;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		if (!connected[index][i]) continue;
		visited[i] = true;
		DFS(i);
	}
	return;
}

int main(void) {
	set_default();
	input();
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		DFS(i);
		cnt++;
	}
	cout << cnt;
	return 0;
}
