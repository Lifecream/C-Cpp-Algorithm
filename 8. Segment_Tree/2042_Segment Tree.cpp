/*
백준 2042번
https://www.acmicpc.net/problem/2042
*/

//algorithm: Segment_Tree

#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000001

using namespace std;

long long tree[4 * MAX_SIZE];
long long arr[MAX_SIZE]; 
int n, m, k;

long long set_tree(int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	tree[node] = set_tree(start, mid, node * 2) + set_tree(mid + 1, end, node * 2 + 1);
	return tree[node];
}

long long sum(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update_tree(int start, int end, int node, int index, long long diff) {
	if (index < start || end < index) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update_tree(start, mid, node * 2, index, diff);
	update_tree(mid + 1, end, node * 2 + 1, index, diff);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	set_tree(1, n, 1);
	for (int i = 0; i < m + k; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			update_tree(1, n, 1, b, c - arr[b]);
			arr[b] = c;
		}
		else cout << sum(1, n, 1, b, c) << '\n';
	}
	return 0;
}
