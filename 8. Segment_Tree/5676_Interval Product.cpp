/*
백준 5676번
https://www.acmicpc.net/problem/5676
*/

//algorithm: Segment_Tree

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_SIZE 100001

using namespace std;

struct NUM {
	int zero_cnt = 0;
	int sign = 1;
};

int n, m;
NUM arr[MAX_SIZE];
NUM tree[4 * MAX_SIZE];
NUM ans;

NUM set_tree(int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	NUM left = set_tree(start, mid, node * 2);
	NUM right = set_tree(mid + 1, end, node * 2 + 1);
	tree[node].zero_cnt += left.zero_cnt;
	tree[node].zero_cnt += right.zero_cnt;
    tree[node].sign *= left.sign;
	tree[node].sign *= right.sign;
	return tree[node];
}

void multiple(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		ans.zero_cnt += tree[node].zero_cnt;
		ans.sign *= tree[node].sign;
		return;
	}
	int mid = (start + end) / 2;
	multiple(start, mid, node * 2, left, right);
	multiple(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, NUM diff) {
	if (index < start || end < index) return;
	tree[node].zero_cnt -= diff.zero_cnt;
	tree[node].sign *= diff.sign;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> m) {
		char output[MAX_SIZE + 1];
		for (int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;
			if (temp > 0) arr[i] = { 0,1 };
			else if (temp < 0) arr[i] = { 0,-1 };
			else arr[i] = { 1,1 };
		}
		set_tree(1, n, 1);
		int p = 0;
		for (int i = 0; i < m; i++) {
			char a;
			int b, c;
			cin >> a >> b >> c;
			if (a == 'C') {
				NUM temp;
				if (c == 0) {
					temp.zero_cnt = 1;
					temp.sign = 1;
				}
				else {
					temp.zero_cnt = 0;
					if (c > 0) temp.sign = 1;
					else temp.sign = -1;
				}
				int x, y;
				if (arr[b].zero_cnt == 0 && temp.zero_cnt == 1) x = -1;
				else if (arr[b].zero_cnt == 1 && temp.zero_cnt == 0) x = 1;
				else x = 0;
				if (arr[b].sign == temp.sign) y = 1;
				else y = -1;
				update(1, n, 1, b, { x,y });
				arr[b] = temp;
			}
			else {
				ans = { 0,1 };
				multiple(1, n, 1, b, c);
				if (ans.zero_cnt) output[p] = 48;
				else if (ans.sign > 0) output[p] = 43;
				else output[p] = 45;
				p++;
			}
		}
		output[p] = '\0';
		cout << output << '\n';
		for (int i = 1; i <= n; i++) {
			tree[i] = { 0,1 };
			arr[i] = { 0,1 };
		}
		for (int i = n + 1; i <= 4 * n; i++) tree[i] = { 0,1 };
	}
	return 0;
}
