/*
백준 1715번
https://www.acmicpc.net/problem/1715
*/

//algorithm: Priority_Queue(Heap)

#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if(a > b) return true;
		else return false;
	}
};

priority_queue<int, vector<int>, cmp> heap;

int main(void){
	int t;
	cin >> t;
	int cnt = 0;
	while(t--){
		int a;
		cin >> a;
		heap.push(a);
	}
        if(heap.size() == 1){
		printf("0");
		return 0;
	}
	int ans = 0;
	while(!heap.empty()){
		int temp = heap.top();
		heap.pop();
		temp += heap.top();
		heap.pop();
		ans += temp;
		if(heap.empty()) break;
		heap.push(temp);
	}
	cout << ans;
	return 0;
}
