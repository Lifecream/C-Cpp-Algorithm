/*
백준 4963번
https://www.acmicpc.net/problem/4963
*/

//algorithm: DFS

#include <iostream>
#include <stdlib.h>

using namespace std;

char map[51][51] = {0,};
int p = 0;
int w,h;
int dx[8] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int compare(const void *a, const void *b){
	return *(int*) a - *(int*) b;
}

void printmap(void){
	for(int i = 1; i<=h; i++){
		for(int j = 1; j<=w; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	return;
}

void dfs(int a, int b){
	map[a][b] = '0';
	for(int i = 0; i<8; i++){
		if(map[a+dx[i]][b+dy[i]] == '1') dfs(a+dx[i],b+dy[i]);
	}
}

int main(void) {
	while(1){
		cin >> w >> h;
		if(w == 0 && h == 0) break;
		p = 0;
		for(int i = 1; i<=h; i++){
			for(int j = 1; j<=w; j++){
				cin >> map[i][j];
			}
		}
		//cout << '\n';
		for(int i = 1; i<=h; i++){
			for(int j = 1; j<=w; j++){
				if(map[i][j] == '1'){
					dfs(i,j);
					//printmap();
					p++;
				}
			}
		}
		cout << p << '\n';
	}
    return 0;
}
