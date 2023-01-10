/*
백준 5972번
https://www.acmicpc.net/problem/5972
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 50001

using namespace std;

struct NODE {
    int node;
    int cost;
    bool operator()(NODE a, NODE b) {
        if (a.cost > b.cost) return true;
        else return false;
    }
};

int n, m;
vector<pair<int, int>> edge[MAX_SIZE];
priority_queue<NODE, vector<NODE>, NODE> pq;
bool visited[MAX_SIZE];

int Dijkstra(NODE start) {
    memset(visited, false, sizeof(visited));
    pq.push(start);
    while (!pq.empty()) {
        NODE top = pq.top();
        pq.pop();
        if (visited[top.node]) continue;
        visited[top.node] = true;
        if (top.node == n) return top.cost;
        for (int i = 0; i < edge[top.node].size(); i++) {
            int arrival = edge[top.node][i].first;
            int weight = edge[top.node][i].second;
            if (visited[arrival]) continue;
            pq.push({ arrival, top.cost + weight });
        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
        edge[b].push_back({ a,c });
    }
    cout << Dijkstra({ 1,0 });
    return 0;
}
