/*
백준 15972번
https://www.acmicpc.net/problem/15972
*/

//algorithm: Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 1001

using namespace std;

struct CMP {
	int x;
	int y;
	int water;
	bool operator()(CMP a, CMP b) {
		if (a.water > b.water) return true;
		else return false;
	}
};

priority_queue <CMP, vector<CMP>, CMP> pq;
int n, m, h;
int map[MAX_SIZE][MAX_SIZE] = { 0, };
int hole[MAX_SIZE][MAX_SIZE][4] = { 0, }; //hole{up:0, down:1, left:2, right:3}, water_level:4;
bool visited[MAX_SIZE][MAX_SIZE];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void check_map(void) {
	cout << '\n';
	cout << "top: {" << pq.top().x << ',' << pq.top().y << "}\n";
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> h;
	int temp;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			hole[i][j][0] = temp;
			hole[i-1][j][1] = temp;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m+1; j++) {
			cin >> temp;
			hole[i][j][2] = temp;
			hole[i][j-1][3] = temp;
		}
	}
}

void set_default(void) {
	for (int i = 1; i <= n; i++) {	//모든 수위를 h로
		for (int j = 1; j <= m; j++) {
			map[i][j] = h;
		}
	}
	for (int i = 1; i <= n; i++) {	//밖과 연결된 수위 조정
		for (int j = 1; j <= m; j++) {
			if (i == 1 && hole[i][j][0] != -1) map[i][j] = min(map[i][j], hole[i][j][0]);
			if (j == 1 && hole[i][j][2] != -1) map[i][j] = min(map[i][j], hole[i][j][2]);
			if (i == n && hole[i][j][1] != -1) map[i][j] = min(map[i][j], hole[i][j][1]);
			if (j == m && hole[i][j][3] != -1) map[i][j] = min(map[i][j], hole[i][j][3]);
			pq.push({ i,j,map[i][j] });
		}
	}
	//check_map();
}

void pq_bfs(void) {
	while(!pq.empty()) {
		//check_map();
		CMP top = pq.top();
		pq.pop();
		if (visited[top.x][top.y]) continue;
		visited[top.x][top.y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if (nx == 0 || ny == 0 || nx > n || ny > m) continue;
			if (hole[top.x][top.y][i] == -1) continue;
			if (visited[nx][ny]) continue;
			map[nx][ny] = min(map[nx][ny], max(hole[top.x][top.y][i], map[top.x][top.y]));
			pq.push({ nx, ny, map[nx][ny] });
		}
	}
}

int ans(void) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum += map[i][j];
		}
	}
	return sum;
}

int main(void) {
	input();
	set_default();
	pq_bfs();
	cout << ans();
	return 0;
}
