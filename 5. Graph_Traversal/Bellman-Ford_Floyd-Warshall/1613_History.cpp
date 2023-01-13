/*
백준 1613번
https://www.acmicpc.net/problem/1613
*/

//algorithm: Floyd_Warshall

#include <iostream>
#include <algorithm>
#define MAX_SIZE 401

using namespace std;

int n, m;
int dist[MAX_SIZE][MAX_SIZE];

void Floyd_Warshall(void) {
    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start <= n; start++) {
            for (int end = 1; end <= n; end++) {
                if (start == mid || mid == end || end == start) continue;
                if (dist[start][mid] == 1 && dist[mid][end] == 1) dist[start][end] = 1;
                if (dist[start][mid] == -1 && dist[mid][end] == -1) dist[start][end] = -1;
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
            dist[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = -1;
        dist[b][a] = 1;
    }
    Floyd_Warshall();
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << '\n';
    }
    return 0;
}
