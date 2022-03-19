/*
백준 11286번
https://www.acmicpc.net/problem/11286
*/

//algorithm: Priority_Queue(Heap)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct CMP {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) return true;
		else if (abs(a) == abs(b)) {
			if (a > b) return true;
			else return false;
		}
		else return false;
	}
};

priority_queue<int, vector<int>, CMP> pq;

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 0) {
			if (pq.empty()) cout << 0;
			else {
				cout << pq.top();
				pq.pop();
			}
			cout << '\n';
		}
		else pq.push(n);
	}
	return 0;
}
