/*
백준 1395번
https://www.acmicpc.net/problem/1395
*/

// algorithm: Lazy Propagation

#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_SIZE 100001

using namespace std;

int arr[MAX_SIZE] = { 0, };
int tree[4 * MAX_SIZE] = { 0, };
bool lazy[4 * MAX_SIZE] = { 0, };
int n, m;

void update_lazy(int start, int end, int node) {
	tree[node] = (end - start + 1) - tree[node];
	if (start != end) {
		lazy[node * 2] = !lazy[node * 2];
		lazy[node * 2 + 1] = !lazy[node * 2 + 1];
	}
	lazy[node] = false;
}

int sum(int start, int end, int node, int left, int right) {
	if (lazy[node]) update_lazy(start, end, node);
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int left, int right) {
	if (lazy[node]) update_lazy(start, end, node);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right);
	update(mid + 1, end, node * 2 + 1, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int o, s, t;
		cin >> o >> s >> t;
		if (o) cout << sum(1, n, 1, s, t) << '\n';
		else update(1, n, 1, s, t);
	}
	return 0;
}
