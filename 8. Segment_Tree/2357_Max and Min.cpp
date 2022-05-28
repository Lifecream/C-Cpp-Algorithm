/*
백준 2357번
https://www.acmicpc.net/problem/2357
*/

//algorithm: Segment_Tree

#include <iostream>
#include <algorithm>
#define MAX_SIZE 100001

using namespace std;

int arr[MAX_SIZE];
int min_tree[4 * MAX_SIZE];
int max_tree[4 * MAX_SIZE];
int n, m;
int minans, maxans;

int set_min(int start, int end, int node) {
	if (start == end) {
		min_tree[node] = arr[start];
		return min_tree[node];
	}
	int mid = (start + end) / 2;
	min_tree[node] = min(set_min(start, mid, node * 2), set_min(mid + 1, end, node * 2 + 1));
	return min_tree[node];
}

int set_max(int start, int end, int node) {
	if (start == end) {
		max_tree[node] = arr[start];
		return max_tree[node];
	}
	int mid = (start + end) / 2;
	max_tree[node] = max(set_max(start, mid, node * 2), set_max(mid + 1, end, node * 2 + 1));
	return max_tree[node];
}

void compare_ans(int index) {
	if (maxans == -1 || maxans < max_tree[index]) maxans = max_tree[index];
	if (minans == -1 || minans > min_tree[index]) minans = min_tree[index];
}

void find_ans(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		compare_ans(node);
		return;
	}
	int mid = (start + end) / 2;
	find_ans(start, mid, node * 2, left, right);
	find_ans(mid + 1, end, node * 2 + 1, left, right);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	set_min(1, n, 1);
	set_max(1, n, 1);
	for (int i = 1; i <= m; i++) {
		minans = -1;
		maxans = -1;
		int a, b;
		cin >> a >> b;
		find_ans(1, n, 1, a, b);
		cout << minans << ' ' << maxans << '\n';
	}
	return 0;
}
