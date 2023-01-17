/*
백준 17836번
https://www.acmicpc.net/problem/17836
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 101

using namespace std;

struct LOCATION {
    int x;
    int y;
    int cost;
    int gram;
    bool operator()(LOCATION a, LOCATION b){
        if(a.cost > b.cost) return true;
        else return false;
    }
};

int n,m,t;
priority_queue<LOCATION, vector<LOCATION>, LOCATION> pq;
int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int Dijkstra(LOCATION s){
    memset(visited,false,sizeof(visited));
    pq.push(s);
    while(!pq.empty()){
        LOCATION top = pq.top();
        pq.pop();
        if(top.cost > t) return -1;
        if(graph[top.x][top.y] == 2) top.gram = 1;
        if(visited[top.x][top.y][top.gram]) continue;
        visited[top.x][top.y][top.gram] = true;
        if(top.x == n && top.y == m) return top.cost;
        for(int i = 0; i<4; i++){
            int nx = top.x + dx[i];
            int ny = top.y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(visited[nx][ny][top.gram]) continue;
            if(graph[nx][ny] == 1 && top.gram == 0) continue;
            pq.push({nx,ny,top.cost+1,top.gram});
        }
    }
    return -1;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> t;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> graph[i][j];
        }
    }
    int ans = Dijkstra({1,1,0,0});
    if(ans == -1) cout << "Fail";
    else cout << ans;
    return 0;
}
