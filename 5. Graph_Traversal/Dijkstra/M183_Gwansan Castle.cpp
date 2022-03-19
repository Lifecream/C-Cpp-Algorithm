/*
마스터즈 183번
https://masterzoj.co.kr/problem/183
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#define MAX_SIZE 101

using namespace std;

struct LOCATION {
	int x;
	int y;
	int wall;
	bool operator()(LOCATION a, LOCATION b) {
		if(a.wall > b.wall) return true;
		else return false;
	}
};

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

priority_queue<LOCATION,vector<LOCATION>,LOCATION> pq;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
LOCATION castle = {0,0,0};
int ans = -1;
int n,m;

void search(int a,int b){
	pq.push(castle);
	visited[castle.x][castle.y] = true;
	while(!pq.empty()){
		castle = pq.top();
		if(castle.x == 1 || castle.x == n || castle.y == 1 || castle.y == m){
			ans = castle.wall;
			pq.pop();
			break;;
		}
		for(int i = 0; i<4; i++){
			int kx = castle.x + dx[i];
			int ky = castle.y + dy[i];
			if(!visited[kx][ky]){
				visited[kx][ky] = true;
				LOCATION temp = {kx,ky,castle.wall+map[kx][ky]};
				pq.push(temp);
			}
		}
		pq.pop();
	}
}

int main(void){
	cin >> n >> m;
	memset(visited,false,sizeof(visited));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			cin >> map[i][j];
			if(map[i][j] == 0){
				castle.x = i;
				castle.y = j;
				castle.wall = 0;
			}
		}
	}
	search(castle.x, castle.y);
	cout << ans;
	return 0;
}
