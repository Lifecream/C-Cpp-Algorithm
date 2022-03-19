/*
백준 1916번
https://www.acmicpc.net/problem/1916
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 1001
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
int n,m,start,arrival;
vector<CMP> map[MAX_SIZE];
bool visited[MAX_SIZE];

void pair_check(int a,int b){
	printf("(%d, %d)\n",a,b);
}

void set_default(void){
	memset(visited,false,sizeof(visited));
}

int Dijkstra(CMP s) {
	int ans;
	pq.push(s);
	while(!pq.empty()){
		CMP top = pq.top();
		//pair_check(top.node,top.cost);
		visited[top.node] = true;
		if(top.node == arrival){
			ans = top.cost;
			break;
		}
		for(int i = 0; i<map[top.node].size(); i++){
			if(visited[map[top.node][i].node]) continue;
			CMP temp = {map[top.node][i].node,top.cost+map[top.node][i].cost};
			//pair_check(i,top.cost+map[top.node][i]);
			pq.push(temp);
		}
		pq.pop();
	}
	return ans;
}

int main(void) {
    cin >> n >> m;
    set_default();
    for(int i = 0; i<m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        CMP temp = {b,w};
        map[a].push_back(temp);
    }
    cin >> start >> arrival;
    CMP s = {start,0};
    cout << Dijkstra(s);
    return 0;
}
