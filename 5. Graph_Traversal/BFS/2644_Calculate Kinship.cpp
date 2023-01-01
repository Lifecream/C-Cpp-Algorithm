/*
백준 2644번
https://www.acmicpc.net/problem/2644
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 101

using namespace std;

int n, m;
int a, b;
vector<int> edge[MAX_SIZE];
bool visited[MAX_SIZE];

int BFS(pair<int, int> start) {
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();
		if (visited[front.first]) continue;
		if (front.first == b) return front.second;
		visited[front.first] = true;
		for (int i = 0; i < edge[front.first].size(); i++) {
			if (!visited[edge[front.first][i]]) q.push({ edge[front.first][i], front.second + 1 });
		}
	}
	return -1;
}

int main(void) {
	memset(visited, false, MAX_SIZE);
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		edge[temp1].push_back(temp2);
		edge[temp2].push_back(temp1);
	}
	cout << BFS({ a,0 });
	return 0;
}
