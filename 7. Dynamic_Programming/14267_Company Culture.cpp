/*
백준 14267번
https://www.acmicpc.net/problem/14267
*/

//algorithm: Dynamic_Programming

#include <iostream>

using namespace std;

int tree[100002];
int compliment[100002] = {0,};
int n,m;

int main(void){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
    	cin >> tree[i];
	}
	for(int j = 0; j<m; j++){
		int p,q;
		cin >> p;
		cin >> q;
		compliment[p] += q;
	}
	for(int i = 1; i<=n; i++){
		compliment[i] += compliment[tree[i]];
    	cout << compliment[i] << ' ';
	}
    return 0;
}
