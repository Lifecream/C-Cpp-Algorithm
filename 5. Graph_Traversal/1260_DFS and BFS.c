/*
백준 1260번
https://www.acmicpc.net/problem/1260
*/

//algorithm: DFS & BFS

#include <stdio.h>
#include <stdlib.h>

int n,m,v;
int queue[1001] = {0,};
int front_pointer = 0;
int back_pointer = 0;
int dfs_visited[1001] = {0,};
int bfs_visited[1001] = {0,};
int connect[1001][1001] = {0,};

void push(int i){
	queue[back_pointer] = i;
	back_pointer++;
}

int pop(void){
	front_pointer++;
	return queue[front_pointer-1];
}

void BFS(int start){
	bfs_visited[start] = 1;
	push(start);
	while(front_pointer - back_pointer){
		int p = pop();
		printf("%d ",p);
		for(int i = 1; i<=n; i++){
			if(p == i) continue;
			if(connect[p][i]){
				if(!bfs_visited[i]){
					bfs_visited[i] = 1;
					push(i);
				}
			}
		}
	}
}

void DFS(int index){
	if(dfs_visited[index] == 1) return;
	dfs_visited[index] = 1;
	printf("%d ",index);
	for(int i = 1; i<=n; i++){
		if(i == index) continue;
		if(connect[index][i]){
			if(!dfs_visited[i]){
				DFS(i);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	scanf("%d %d %d",&n,&m,&v);
	for(int i = 0; i<m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		connect[a][b] = 1;
		connect[b][a] = 1;
	}
	DFS(v);
	printf("\n");
	BFS(v);
	return 0;
}
