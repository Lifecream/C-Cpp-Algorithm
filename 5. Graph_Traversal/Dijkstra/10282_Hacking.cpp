/*
백준 10282번
https://www.acmicpc.net/problem/10282
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 10001
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

pair<int,int> Dijkstra(void) {
    int n, d, c;
    cin >> n >> d >> c;
    vector<pair<int, int>> edge[MAX_SIZE];
    priority_queue<NODE, vector<NODE>, NODE> pq;
    int dist[MAX_SIZE] = { 0, };
    bool visited[MAX_SIZE];
    memset(visited, false, sizeof(visited)); //visited 초기화
    for (int i = 1; i <= n; i++) dist[i] = INF; //dist 초기화
    dist[c] = 0;
    for (int i = 0; i < d; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        edge[b].push_back({ a,s });
    }
    pq.push({ c,0 });
    pair<int, int> ans = make_pair(0, 0);
    while (!pq.empty()) {
        NODE top = pq.top();
        pq.pop();
        if (visited[top.node]) continue;
        visited[top.node] = true;
        for (int i = 0; i < edge[top.node].size(); i++) {
            int arrival = edge[top.node][i].first;
            int weight = edge[top.node][i].second;
            if (!visited[arrival]) {
                dist[arrival] = min(dist[arrival], top.cost + weight);
                pq.push({ arrival, top.cost + weight });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] < INF) {
            ans.first++;
            ans.second = max(ans.second, dist[i]);
        }
    }
    return ans;
}

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        pair<int, int> ans = Dijkstra();
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}
