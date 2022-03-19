/*
백준 3078번
https://www.acmicpc.net/problem/3078
*/

//algorithm: Stack

#include <iostream>
#include <queue>
#include <cstring>
#define MAX_SIZE 300001

using namespace std;

queue<unsigned long long> q;
unsigned long long students[MAX_SIZE];

int main(void){
	int n,k;
	unsigned long long ans = 0;
	unsigned long long cnt[21] = {0,};
	cin >> n >> k;
	for(int i = 0; i<n; i++){
		char s[21];
		cin >> s;
		students[i] = strlen(s);
	}
	for(int i = 0; i<n; i++){
		q.push(students[i]);
		ans += cnt[students[i]];
		cnt[students[i]] ++;
		if(q.size() > k){
			cnt[q.front()]--;
			q.pop();
		}
	}
	cout << ans;
	return 0;
}
