/*
마스터즈 224번
https://masterzoj.co.kr/problem/224
*/

//algorithm: Priority_Queue(Heap)

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX_SIZE 1001

using namespace std;

struct LOCATION{
	int x;
	int y;
	int cnt_transfer;
	int facing;
	bool operator()(LOCATION a, LOCATION b){
		if(a.cnt_transfer > b.cnt_transfer) return true;
		else return false;
	} 
};

priority_queue <LOCATION,vector<LOCATION>,LOCATION> pq;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int n,m,x,y;
LOCATION l = {1,1,-1,0};

void horizontal_push(LOCATION top){	//facing == 1
	for(int i = 1; i<=m; i++){
		if(visited[top.x][i]) continue;
		if(!map[top.x][i]) continue;
		LOCATION b = {top.x,i,top.cnt_transfer+1,2};
		visited[top.x][i] = true;
		pq.push(b);
	}
}

void vertical_push(LOCATION top){	//facing == 2
	for(int i = 1; i<=n; i++){
		if(visited[i][top.y]) continue;
		if(!map[i][top.y]) continue;
		LOCATION b = {i,top.y,top.cnt_transfer+1,1};
		visited[i][top.y] = true;
		pq.push(b);
	}
}

int search(void){
	int ans = 0;
	pq.push(l);
	visited[1][1] = true;
	while(!pq.empty()){
		LOCATION temp = pq.top();
		if(temp.x == x && temp.y == y){
			ans = temp.cnt_transfer;
			pq.pop();
			break;
		}
		if(temp.facing == 1) horizontal_push(temp);
		else if(temp.facing == 2) vertical_push(temp);
		else{
			horizontal_push(temp);
			vertical_push(temp);
		}
		pq.pop();
	}
	if(ans) return ans;
	else return -1;
}

int main(void) {
	memset(map,0,sizeof(map));
	memset(visited,false,sizeof(visited));
	scanf("%d %d %d %d",&n,&m,&x,&y);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d",&map[i][j]);
		}
	}
	if(x == 1 && y == 1){
		printf("0");
		return 0;
	}
	printf("%d",search());
	return 0;
}
