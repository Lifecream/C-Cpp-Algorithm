/*
백준 6087번
https://www.acmicpc.net/problem/6087
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 101
using namespace std;

struct LOCATION {
    int x;
    int y;
    int cnt;
    int facing; //before_node -> 0: horizontal / 1: vertical / 2: initial
    bool operator()(LOCATION a, LOCATION b) {
        if (a.cnt > b.cnt) return true;
        else return false;
    }
};

char map[101][101];
int visited[101][101][2];
int w, h;
pair<int, int> c1, c2;
priority_queue<LOCATION, vector<LOCATION>, LOCATION> pq;

void horizontal_search(LOCATION start) { //next_facing: 1
    for (int i = 1; i <= h; i++) { //go up
        if (start.x - i < 1) break;
        if (map[start.x - i][start.y] == '*') break;
        if (visited[start.x - i][start.y][0] == -1) {
            pq.push({ start.x - i,start.y,start.cnt + 1,0 });
        }
    }
    for (int i = 1; i <= h; i++) { //go down
        if (start.x + i > h) break;
        if (map[start.x + i][start.y] == '*') break;
        if (visited[start.x + i][start.y][0] == -1) {
            pq.push({ start.x + i,start.y,start.cnt + 1,0 });
        }
    }
}

void vertical_search(LOCATION start) { //next_facing: 0
    for (int i = 1; i <= w; i++) { //go left
        if (start.y - i < 1) break;
        if (map[start.x][start.y - i] == '*') break;
        if (visited[start.x][start.y - i][1] == -1) {
            pq.push({ start.x,start.y - i,start.cnt + 1,1 });
        }
    }
    for (int i = 1; i <= w; i++) { //go down
        if (start.y + i > w) break;
        if (map[start.x][start.y + i] == '*') break;
        if (visited[start.x + i][start.y + i][1] == -1) {
            pq.push({ start.x,start.y + i,start.cnt + 1,1 });
        }
    }
}

int Dijkstra(LOCATION start) {
    pq.push(start);
    while (!pq.empty()) {
        LOCATION top = pq.top();
        pq.pop();
        if (visited[top.x][top.y][top.facing] != -1) continue;
        if (top.x == c2.first && top.y == c2.second) {  //c2에 도착했을 경우 
            return top.cnt;
        }
        visited[top.x][top.y][top.facing] = top.cnt;
        if (top.facing == 0) {
            vertical_search(top);
        }
        else if (top.facing == 1) {
            horizontal_search(top);
        }
        else {
            horizontal_search(top);
            vertical_search(top);
        }
    }
}

int main(void) {
    memset(visited, -1, sizeof(visited));
    bool flag = false;
    cin >> w >> h;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'C') {
                if (flag) {
                    c2 = { i,j };
                    continue;
                }
                c1 = { i,j };
                flag = true;
            }
        }
    }
    cout << Dijkstra({ c1.first, c1.second, 0, 2 }) - 1;
    return 0;
}
