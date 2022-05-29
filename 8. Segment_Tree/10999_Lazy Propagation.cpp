/*
백준 10999번
https://www.acmicpc.net/problem/10999
*/

//algorithm: Segment_Tree (Lazy Propagation)

#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000001

using namespace std;

long long tree[4 * MAX_SIZE];
long long lazy[4 * MAX_SIZE] = { 0, };
long long arr[MAX_SIZE];
int n, m, k;

long long make_tree(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = make_tree(start, mid, node * 2) + make_tree(mid + 1, end, node * 2 + 1);
}

void update_lazy(int start, int end, int node) {
	tree[node] += (long long)(end - start + 1) * lazy[node];
	if (start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

long long sum(int start, int end, int node, int left, int right) {
	if (lazy[node]) update_lazy(start, end, node);
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int left, int right, long long diff) {
	if (lazy[node]) update_lazy(start, end, node);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		tree[node] += (long long)(end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, diff);
	update(mid + 1, end, node * 2 + 1, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	make_tree(1, n, 1);
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long d;
			cin >> d;
			update(1, n, 1, b, c, d);
		}
		else cout << sum(1, n, 1, b, c) << '\n';
	}
	return 0;
}
