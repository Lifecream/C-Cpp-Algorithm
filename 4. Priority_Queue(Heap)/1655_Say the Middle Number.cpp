/*
백준 1655번
https://www.acmicpc.net/problem/1655
*/

//algorithm: Priority_Queue(Heap)

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct CMP {
	bool operator()(int a, int b) {
		if (a > b) return true;
		else return false;
	}
};

priority_queue<int, vector<int>, CMP> min_pq;
priority_queue<int> max_pq; 
int n;

void DEBUG(void) {
	cout << "( ";
	if (max_pq.empty()) cout << "EMPTY";
	else cout << max_pq.top();
	cout << " , ";
	if (min_pq.empty()) cout << "EMPTY";
	else cout << min_pq.top();
	cout << " )\n";
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		if (i % 2) max_pq.push(temp);
		else min_pq.push(temp);
		if (max_pq.empty() || min_pq.empty()) {
			cout << temp << '\n';
			continue;
		}
		if (max_pq.top() > min_pq.top()) {
			int temp1 = max_pq.top(), temp2 = min_pq.top();
			max_pq.pop();
			min_pq.pop();
			max_pq.push(temp2);
			min_pq.push(temp1);
		}
		cout << max_pq.top() << '\n';
		//DEBUG();
	}
	return 0;
}
