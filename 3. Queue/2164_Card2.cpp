/*
백준 2164번
https://www.acmicpc.net/problem/2164
*/

//algorithm: Queue

#include <iostream>
#include <queue>

using namespace std;

int main(void){
	queue<int> a;
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++){
		a.push(i);
	}
	while(a.size() != 1){
		a.pop();
		a.push(a.front());
		a.pop();
	}
	cout << a.front();
	return 0;
}
