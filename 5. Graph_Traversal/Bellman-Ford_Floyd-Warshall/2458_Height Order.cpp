/*
백준 2458번
https://www.acmicpc.net/problem/2458
*/

//algorithm: Floyd_Warshall

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_SIZE 501
#define INF 987654321

using namespace std;

int n, m;
int dist[MAX_SIZE][MAX_SIZE];
queue<int> temp;

void Floyd_Warshall(void) {
    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start <= n; start++) {
            if (mid == start) continue;
            for (int end = 1; end <= n; end++) {
                if (end == start || end == mid) continue;
                dist[start][end] = min(dist[start][end], dist[start][mid] + dist[mid][end]);
            }
        }
    }
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
    Floyd_Warshall();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (dist[i][j] != INF || dist[j][i] != INF) {
                cnt++;
            }
        }
        if (cnt == n - 1) ans++;
    }
    cout << ans;
    return 0;
}
