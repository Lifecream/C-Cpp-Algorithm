/*
백준 2606번
https://www.acmicpc.net/problem/2606
*/

//algorithm: DFS

#include <stdio.h>

int connect[101][101] = {0,};
int visited[101] = {0,};
int cnt = 0;
int v,n;

void dfs(int node){
	visited[node] = 1;
	for(int i = 1; i<=v; i++){
		if(connect[node][i]){
			if(!visited[i]){
				dfs(i);
				cnt++;
			}
		}
	}
}

int main(void) {
	scanf("%d %d",&v,&n);
	for(int i = 0; i<n; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		connect[a][b] = 1;
		connect[b][a] = 1;
	}
	dfs(1);
	printf("%d",cnt);
	return 0;
}
