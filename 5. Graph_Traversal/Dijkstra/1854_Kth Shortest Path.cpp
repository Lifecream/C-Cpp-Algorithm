/*
백준 1854번
https://www.acmicpc.net/problem/1854
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 1001

using namespace std;

struct NODE {
    int node;
    int cost;
    bool operator()(NODE a, NODE b) {
        if (a.cost > b.cost) return true;
        else return false;
    }
};

struct COMPARE {
    bool operator()(int a, int b) {
        if (a < b) return true;
        else return false;
    }
};

int n, m, k;
int dist[MAX_SIZE];
int cnt[MAX_SIZE];
vector<pair<int,int>> edge[MAX_SIZE];
priority_queue<NODE, vector<NODE>, NODE> pq;
priority_queue<int, vector<int>, COMPARE> kth[MAX_SIZE];

void Dijkstra(NODE start) {
    memset(dist, -1, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    pq.push(start);
    kth[start.node].push(0);
    while (!pq.empty()) {
        NODE top = pq.top();
        pq.pop();
        if (cnt[top.node] >= k) continue;
        cnt[top.node]++;
        for (int i = 0; i < edge[top.node].size(); i++) {
            int arrival = edge[top.node][i].first;
            int weight = edge[top.node][i].second;
            pq.push({ arrival,top.cost + weight });
            kth[arrival].push(top.cost + weight);
            if (kth[arrival].size() > k) kth[arrival].pop();
        }
    }
    for (int i = 1; i <= n; i++) {
        if (kth[i].size() == k) dist[i] = kth[i].top();
    }
}

int main(void) {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
    }
    Dijkstra({ 1,0 });
    for (int i = 1; i <= n; i++) cout << dist[i] << '\n';
    return 0;
}
