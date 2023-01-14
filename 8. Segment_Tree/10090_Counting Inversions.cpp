/*
백준 10090번
https://www.acmicpc.net/problem/10090
*/

//algorithm: Segment_Tree

#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000001

using namespace std;

int n;

struct segTree {
    long long tree[4 * MAX_SIZE];
    segTree() {
        for (int i = 0; i < 4 * MAX_SIZE; i++) tree[i] = 0;
    }
    void update(int start, int end, int node, int index) {
        if (index < start || end < index) return;
        tree[node] += 1;
        if (start == end) return;
        int mid = (start + end) / 2;
        update(start, mid, node * 2, index);
        update(mid + 1, end, node * 2 + 1, index);
    }
    long long query(int start, int end, int node, int left, int right) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
    }
} tree;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        ans += tree.query(1, n, 1, temp + 1, n);
        tree.update(1, n, 1, temp);
    }
    cout << ans;
    return 0;
}
