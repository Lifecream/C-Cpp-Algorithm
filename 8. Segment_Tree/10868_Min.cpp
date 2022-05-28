/*
백준 10868번
https://www.acmicpc.net/problem/10868
*/

//algorithm: Segment_Tree

#include <iostream>
#include <algorithm>
#define MAX_SIZE 100001

using namespace std;

int arr[MAX_SIZE];
int tree[4 * MAX_SIZE];
int n, m;
int ans;

int set_tree(int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	tree[node] = min(set_tree(start, mid, node * 2), set_tree(mid + 1, end, node * 2 + 1));
	return tree[node];
}

void find_ans(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		if (ans == -1 || ans > tree[node]) ans = tree[node];
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
	set_tree(1, n, 1);
	for (int i = 1; i <= m; i++) {
		ans = -1;
		int a, b;
		cin >> a >> b;
		find_ans(1, n, 1, a, b);
		cout << ans << '\n';
	}
	return 0;
}
