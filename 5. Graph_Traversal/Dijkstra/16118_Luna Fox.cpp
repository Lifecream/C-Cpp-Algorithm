/*
백준 16118번
https://www.acmicpc.net/problem/16118
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 4001
#define INF 2000000000

using namespace std;

struct CMP{
    int node;
    int cost;
    int counter;
    bool operator()(CMP a, CMP b){
        if(a.cost > b.cost) return true;
        else return false;
    } 
};

priority_queue <CMP,vector<CMP>,CMP> pq;
int n,m;
vector<CMP> map[MAX_SIZE];
int fox_dist[MAX_SIZE] = {0,0,};
int wolf_dist[MAX_SIZE][2] = {0,0,0,0,};

void dist_check(void){
    cout << "fox_dist[ ";
    for(int i = 1; i<=n; i++){
        if(fox_dist[i] >= INF) cout << "INF ";
        else cout << fox_dist[i] << ' ';
    }
    cout << "]\nwolf_dist[ ";
    for(int i = 1; i<=n; i++){
        cout << '(';
        for(int j = 0; j<2; j++){
            if(wolf_dist[i][j] >= INF) cout << "INF";
            else cout << wolf_dist[i][j];
            if(j==0) cout << ',';
        }
        cout << ") ";
    }
    cout << "]\n";
    return;
}

void fox_Dijkstra(CMP s){
    bool visited[MAX_SIZE];
    memset(visited,false,sizeof(visited));
    int cnt = n;
    pq.push(s);
    while(!pq.empty()){
        CMP top = pq.top();
        if(visited[top.node]){
            pq.pop();
            continue;
        }
        visited[top.node] = true;
        cnt--;
        if(cnt == 0) break;
        for(int i = 0; i<map[top.node].size(); i++){
            CMP arrival = map[top.node][i];
            if(visited[arrival.node]) continue;
            fox_dist[arrival.node] = min(fox_dist[arrival.node],top.cost+arrival.cost);
            CMP temp = {arrival.node,top.cost+arrival.cost,0};
            pq.push(temp);
        }
        pq.pop();
    }
}

void wolf_Dijkstra(CMP s){
    while(!pq.empty()) pq.pop(); //pq 초기화 
    bool visited[MAX_SIZE][2];
    memset(visited,false,sizeof(visited));
    pq.push(s);
    while(!pq.empty()){
        CMP top = pq.top();
        int slow = top.counter % 2;
        if(visited[top.node][slow]){
            pq.pop();
            continue;
        }
        visited[top.node][slow] = true;
        for(int i = 0; i<map[top.node].size(); i++){
            CMP arrival = map[top.node][i];
            if(slow == 0){
            	if(visited[arrival.node][1]) continue; 
                wolf_dist[arrival.node][1] = min(wolf_dist[arrival.node][1],top.cost+(arrival.cost)/2);
                CMP temp = {arrival.node,top.cost+(arrival.cost)/2,top.counter+1};
                pq.push(temp);
            }
            if(slow == 1){
            	if(visited[arrival.node][0]) continue; 
                wolf_dist[arrival.node][0] = min(wolf_dist[arrival.node][0],top.cost+(arrival.cost)*2);
                CMP temp = {arrival.node,top.cost+(arrival.cost)*2,top.counter+1};
                pq.push(temp);
            }
        }
        pq.pop();
    }
}

int output(void){
    int cnt = 0;
    for(int i = 2; i<MAX_SIZE; i++){
        fox_dist[i] = INF;
        wolf_dist[i][0] = INF;
        wolf_dist[i][1] = INF;
    }
    CMP s = {1,0,0};
    fox_Dijkstra(s);
    wolf_Dijkstra(s);
    //dist_check();
    for(int i = 2; i<=n; i++){
        if(fox_dist[i] < min(wolf_dist[i][0],wolf_dist[i][1])) cnt++;
    }
    return cnt;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a,b,d;
        cin >> a >> b >> d;
        CMP temp = {b,d*2,0};
        map[a].push_back(temp);
        temp = {a,d*2,0};
        map[b].push_back(temp);
    }
    cout << output();
    return 0;
}
