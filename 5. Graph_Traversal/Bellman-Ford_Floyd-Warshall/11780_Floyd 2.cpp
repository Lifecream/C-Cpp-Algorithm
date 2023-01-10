/*
백준 11780번
https://www.acmicpc.net/problem/11780
*/

//algorithm: Floyd_Warshall

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_SIZE 101
#define INF 987654321

using namespace std;

int n, m;
int dist[MAX_SIZE][MAX_SIZE];
int route[MAX_SIZE][MAX_SIZE];
queue<int> temp;

void Print_Route(int start, int end) {
    if (start == end) {
        temp.push(end);
        cout << temp.size() << ' ';
        return;
    }
    temp.push(start);
    start = route[start][end];
    Print_Route(start, end);
    return;
}

void output(void) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << 0 << '\n';
                continue;
            }
            int start = i;
            int end = j;
            queue<int> q;
            while (start != end) {
                q.push(start);
                start = route[start][end];
            }
            q.push(end);
            cout << q.size() << ' ';
            while (!q.empty()) {
                cout << q.front() << ' ';
                q.pop();
            }
            cout << '\n';
        }
    }
    return;
}

void Floyd_Warshall(void) {
    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start <= n; start++) {
            if (mid == start) continue;
            for (int end = 1; end <= n; end++) {
                if (end == start || end == mid) continue;
                if (dist[start][end] > dist[start][mid] + dist[mid][end]) {
                    dist[start][end] = dist[start][mid] + dist[mid][end];
                    route[start][end] = route[start][mid];
                }
            }
        }
    }
    output();
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
            route[i][j] = 0;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        route[a][b] = b;
    }
    Floyd_Warshall();
    return 0;
}
