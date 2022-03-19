/*
백준 1158번
https://www.acmicpc.net/problem/1158
*/

//algorithm: Queue

#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> a;
	int n,k;
	cin >> n >> k;
	for(int i = 1; i<=n; i++){
		a.push(i);
	}
	cout << '<';
	while(a.size()){
		for(int i = 0; i<k-1; i++){
			a.push(a.front());
			a.pop();
		}
		cout << a.front();
		if(a.size() > 1) cout << ", ";
		a.pop();
	}
	cout << '>';
	return 0;
}
