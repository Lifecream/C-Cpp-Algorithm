/*
백준 13549번
https://www.acmicpc.net/problem/13549
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 100001

using namespace std;

struct CMP {
	int node;
	int cost;
	bool operator()(CMP a, CMP b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

int n, k;
vector<CMP> map[MAX_SIZE];
priority_queue<CMP, vector<CMP>, CMP> pq;
bool visited[MAX_SIZE];

void input(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
}

int Dijkstra(CMP start) {
	int ans = -1;
	pq.push(start);
	memset(visited, false, sizeof(visited));
	while (!pq.empty()) {
		CMP top = pq.top();
		pq.pop();
		if (top.node == k) {
			ans = top.cost;
			break;
		}
		if (visited[top.node]) continue;
		visited[top.node] = true;
		if (top.node * 2 < MAX_SIZE) pq.push({ top.node * 2,top.cost });
		if (top.node - 1 >= 0) pq.push({ top.node - 1,top.cost + 1 });
		if (top.node + 1 < MAX_SIZE) pq.push({ top.node + 1,top.cost + 1 });
	}
	return ans;
}

int main(void) {
	input();
	cout << Dijkstra({ n,0 });
	return 0;
}
