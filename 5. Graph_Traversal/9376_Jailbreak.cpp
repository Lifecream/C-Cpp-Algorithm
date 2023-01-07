/*
백준 9376번
https://www.acmicpc.net/problem/9376
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 102
#define INF 1000000

using namespace std;

struct LOCATION {
    int x;
    int y;
    int cost;
    bool operator()(LOCATION a, LOCATION b) {
        if (a.cost > b.cost) return true;
        else return false;
    }
};

int h, w;
char map[MAX_SIZE][MAX_SIZE];
queue<LOCATION> person;
bool visited[MAX_SIZE][MAX_SIZE];
priority_queue<LOCATION, vector<LOCATION>, LOCATION> pq;

int Jailbreak(void) {
    int ans = INF;
    int dx[] = { 1,-1,0,0 };
    int dy[] = { 0,0,1,-1 };
    int door[MAX_SIZE][MAX_SIZE][3] = { 0, }; // 0: Helper, 1: Prisoner 1, 2: Prisoner 2

    for (int _ = 0; _ <= 2; _++) { // 0: Helper, 1: Prisoner 1, 2: Prisoner 2
        memset(visited, false, sizeof(visited));
        pq.push(person.front());
        person.pop();
        while (!pq.empty()) {
            LOCATION top = pq.top();
            pq.pop();
            if (visited[top.x][top.y]) continue;
            visited[top.x][top.y] = true;
            door[top.x][top.y][_] = top.cost;
            for (int i = 0; i < 4; i++) {
                int nx = top.x + dx[i];
                int ny = top.y + dy[i];
                if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
                if (visited[nx][ny]) continue;
                if (map[nx][ny] == '*') continue;
                else if (map[nx][ny] == '#') pq.push({ nx,ny,top.cost + 1 });
                else pq.push({ nx,ny,top.cost });
            }
        }

        // LOCATION we can't reach
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (map[i][j] == '*') continue;
                if (!visited[i][j]) door[i][j][_] = INF;
            }
        }
    }

    // Get Answer
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (map[i][j] == '*') continue;
            int sum = 0;
            if (map[i][j] == '#') sum -= 2; // Preventing Door's Reduplication
            for (int _ = 0; _ < 3; _++) sum += door[i][j][_];
            ans = min(ans, sum);
        }
    }

    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        // Helper's Start
        person.push({ 0,0 });

        // input
        cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
                if (map[i][j] == '$') person.push({ i,j,0 }); // Prisoner's Start
            }
        }

        // map's edge = '.'
        for (int i = 0; i <= h + 1; i++) {
            map[i][0] = '.';
            map[i][w + 1] = '.';
        }
        for (int i = 0; i <= w+1; i++) {
            map[0][i] = '.';
            map[h+1][i] = '.';
        }

        cout << Jailbreak() << '\n';
    }
    return 0;
}
