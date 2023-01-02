/*
백준 2211번
https://www.acmicpc.net/problem/2211
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 1001
#define INF 987654321

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
int dist[MAX_SIZE];
int path[MAX_SIZE];
vector<pair<int, int>> edge[MAX_SIZE];
bool visited[MAX_SIZE];
priority_queue<NODE, vector<NODE>, NODE> pq;

void DEBUG_dist(void) {
    cout << "-------- DEBUG --------\n\n";
    cout << "dist = [ ";
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << "]\n\n";
    cout << "-----------------------\n";
}

void DEBUG_path(void) {
    cout << "-------- DEBUG --------\n\n";
    cout << "path = [ ";
    for (int i = 1; i <= n; i++) {
        cout << path[i] << ' ';
    }
    cout << "]\n\n";
    cout << "-----------------------\n";
}

void Dijkstra(NODE start) {
    memset(visited, false, sizeof(visited));
    memset(path, -1, sizeof(path));
    for (int i = 0; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    path[1] = 0;
    pq.push(start);
    while (!pq.empty()) {
        NODE top = pq.top();
        pq.pop();
        if (visited[top.node]) continue;
        visited[top.node] = true;
        for (int i = 0; i < edge[top.node].size(); i++) {
            int arrival = edge[top.node][i].first;
            if (!visited[arrival]) {
                if (dist[arrival] > dist[top.node] + edge[top.node][i].second) {
                    dist[arrival] = dist[top.node] + edge[top.node][i].second;
                    pq.push({ arrival, dist[arrival] });
                    path[arrival] = top.node;
                }
            }
        }
    }
    cout << n - 1 << '\n';
    for (int i = 2; i <= n; i++) {
        cout << i << ' ' << path[i] << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({ b, c });
        edge[b].push_back({ a, c });
    }
    Dijkstra({ 1,0 });
    return 0;
}
