/*
백준 1753번
https://www.acmicpc.net/problem/1753
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 20001
#define INF 2000000000 //20억 

using namespace std;

struct CMP{
	int node;
	int cost;
	bool operator()(CMP a, CMP b){
		if(a.cost > b.cost) return true;
		else return false;
	} 
};

priority_queue <CMP,vector<CMP>,CMP> pq;
int v,e,k;
vector<CMP> map[MAX_SIZE];
bool visited[MAX_SIZE];


void dist_check(int* d){
	cout << "dist[";
	for(int i = 1; i<=v; i++){
		if(d[i] >= INF) cout << " INF";
		else cout <<' '<< d[i];
	}
	cout << " ]\n";
}

void Dijkstra(CMP s) {
	int dist[MAX_SIZE];
	for(int i = 0; i<MAX_SIZE; i++) dist[i] = INF;
	dist[s.node] = 0;
	memset(visited,false,sizeof(visited));
	//dist_check(dist);
	int cnt = v;
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
			dist[arrival.node] = min(dist[arrival.node],top.cost+arrival.cost);
			CMP temp = {arrival.node,top.cost+arrival.cost};
			pq.push(temp);
		}
		pq.pop();
	}
	for(int i = 1; i<=v; i++){
		if(dist[i] >= INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}

int main(void) {
    cin >> v >> e >> k;
    for(int i = 0; i<e; i++){
        int a,b,w;
        cin >> a >> b >> w;
        CMP temp = {b,w};
        map[a].push_back(temp);
    }
    CMP s = {k,0};
    Dijkstra(s);
    return 0;
}
