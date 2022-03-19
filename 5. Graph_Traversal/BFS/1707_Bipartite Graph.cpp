/*
백준 1707번
https://www.acmicpc.net/problem/1707
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 20001

using namespace std;

struct LOCATION {
	int node;
	int group;
};

queue<LOCATION> q;
vector<int> map[MAX_SIZE];
int nodegroup[MAX_SIZE];
int n, m;

void group_check(void) {
	cout << "nodegroup[ ";
	for (int i = 1; i <= n; i++) {
		cout << nodegroup[i] << ", ";
	}
	cout << "]\n";
}

void set_default(void) {
	memset(nodegroup, 0, sizeof(nodegroup));
	for (int i = 1; i < MAX_SIZE; i++) {
		while (!map[i].empty()) map[i].pop_back();
	}
}

bool checking(LOCATION start) {
	while (!q.empty()) q.pop();
	nodegroup[start.node] = start.group;
	q.push(start);
	while (!q.empty()) {
		LOCATION top = q.front();
		q.pop();
		//group_check();
		for (int i = 0; i < map[top.node].size(); i++) {
			int temp = map[top.node][i];
			if (nodegroup[temp]) {
				if (top.group == nodegroup[temp]) return false;
				else continue;
			}
			else {
				if (top.group == 1) {
					q.push({ temp,2 });
					nodegroup[temp] = 2;
				}
				else {
					q.push({ temp,1 });
					nodegroup[temp] = 1;
				}
			}
		}
	}
	return true;
}

int main(void) {
	int k;
	cin >> k;
	while (k--) {
		cin >> n >> m;
		set_default();
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}
		bool printed = false;
		for (int i = 1; i <= n; i++) {
			if (!nodegroup[i]) {
				if (checking({ i,1 })) continue;
				cout << "NO\n";
				printed = true;
				break;
			}
		}
		if(!printed) cout << "YES\n";
	}
	return 0;
}
