/*
백준 14938번
https://www.acmicpc.net/problem/14938
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 101
#define INF 987654321

using namespace std;

struct NODE {
    int node;
    int cost;
    int sum;
    bool operator()(NODE a, NODE b) {
        if (a.cost > b.cost) return true;
        else return false;
    }
};

int n, m, r;
int item[MAX_SIZE];
vector<pair<int,int>> edge[MAX_SIZE];

int Dijkstra(NODE start) {
    int ans = 0;
    bool visited[MAX_SIZE];
    memset(visited, false, sizeof(visited));
    priority_queue<NODE, vector<NODE>, NODE> pq;
    pq.push(start);
    while (!pq.empty()) {
        NODE top = pq.top();
        pq.pop();
        if (top.cost > m) continue;
        if (visited[top.node]) continue;
        visited[top.node] = true;
        ans += item[top.node];
        for (int i = 0; i < edge[top.node].size(); i++) {
            int arrival = edge[top.node][i].first;
            int weight = edge[top.node][i].second;
            if (!visited[arrival]) {
                pq.push({ arrival,top.cost + weight, top.sum + item[arrival] });
            }
        }
    }
    return ans;
}

int main(void) {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> item[i];
    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
        edge[b].push_back({ a,c });
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, Dijkstra({ i,0,item[i] }));
    cout << ans;
    return 0;
}
