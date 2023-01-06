/*
백준 1719번
https://www.acmicpc.net/problem/1719
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 201
#define INF 987654321

using namespace std;

struct NODE {
    int node;
    int cost;
    int first;
    bool operator()(NODE a, NODE b) {
        if (a.cost > b.cost) return true;
        else return false;
    }
};

int n, m;
int vertex[MAX_SIZE][MAX_SIZE];
vector<pair<int, int>> edge[MAX_SIZE];

void Dijkstra(NODE start) {
    bool visited[MAX_SIZE];
    memset(visited, false, sizeof(visited));
    priority_queue<NODE, vector<NODE>, NODE> pq;
    pq.push(start);
    int before;
    while (!pq.empty()) {
        NODE top = pq.top();
        pq.pop();
        if (visited[top.node]) continue;
        vertex[start.node][top.node] = top.first;
        visited[top.node] = true;
        for (int i = 0; i < edge[top.node].size(); i++) {
            int arrival = edge[top.node][i].first;
            int weight = edge[top.node][i].second;
            if (!visited[arrival]) { 
                if (top.first == -1) pq.push({ arrival, top.cost + weight, arrival });
                else pq.push({ arrival, top.cost + weight, top.first });
            }
        }
    }
}

int main(void) {
    memset(vertex, 0, sizeof(vertex));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
        edge[b].push_back({ a,c });
    }
    for (int i = 1; i <= n; i++) Dijkstra({ i,0,-1 });
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else cout << vertex[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
