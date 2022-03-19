/*
백준 11000번
https://www.acmicpc.net/problem/11000
*/

//algorithm: Priority_Queue(Heap)

#include <iostream>
#include <stdlib.h>
#include <queue>
#define MAX_SIZE 200001

using namespace std;

struct Time{
	int s;
	int t;
};

struct cmp {
	bool operator()(int a, int b) {
		if(a > b) return true;
		else return false;
	}
};

int compare(const void *a,const void *b){
	return *(int*)a - *(int*)b;
}

priority_queue<int,vector<int>,cmp> pq;

int main(void){
	Time a[MAX_SIZE];
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> a[i].s >> a[i].t;
	}
	qsort(a,n,sizeof(Time),compare);
	pq.push(a[0].t);
	for(int i = 1; i<n; i++){
		if(pq.top() <= a[i].s) pq.pop();
		pq.push(a[i].t);
	}
	cout << pq.size();
	return 0;
}
