/*
백준 2667번
https://www.acmicpc.net/problem/2667
*/

//algorithm: DFS

#include <iostream>
#include <stdlib.h>

using namespace std;

char map[26][26] = {0,};
int cnt[1000] = {0,};
int p = 0;
int n;

int compare(const void *a, const void *b){
	return *(int*) a - *(int*) b;
}

void printmap(void){
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	return;
}

void dfs(int a, int b){
	map[a][b] = '0';
	cnt[p]++;
	if(map[a+1][b] == '1') dfs(a+1,b);
	if(map[a-1][b] == '1') dfs(a-1,b);
	if(map[a][b+1] == '1') dfs(a,b+1);
	if(map[a][b-1] == '1') dfs(a,b-1);
}

int main(void) {
	cin >> n;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin >> map[i][j];
		}
	}
	//cout << '\n';
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(map[i][j] == '1'){
				dfs(i,j);
				//printmap();
				p++;
			}
		}
	}
	cout << p << '\n';
	qsort(cnt,p,sizeof(int),compare);
	for(int i = 0; i<p; i++){
		cout << cnt[i] << '\n';
	}
    return 0;
}
