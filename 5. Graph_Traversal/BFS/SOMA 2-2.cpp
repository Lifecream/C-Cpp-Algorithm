/*
SW 마에스트로 코딩테스트 2차 2번 문제

N명의 학생, M개의 선호도 조사 수, K개의 친구 관계

선호도 조사를 하지 않은 학생이 너무 많아 그들의 선호도를 다음과 같이 산출하기로 했다.

* 선호도 조사를 하지 않은 학생 A가 있을 때 A의 선호도는 A의 친구들이 응답한 선호도의 평균으로 정한다.

* 친구 관계는 다음과 같이 정의한다.
	A와 B가 친구고 B와 C가 친구면 A와 C도 친구이다.

다음과 같이 선호도를 계산할 때 전체 선호도의 평균을 출력하라.

입력: 첫줄에 N,M,K (1 <= N <= 100000, 1 <= M <= N, 1 <= K <= M-1)
이어지는 m줄에 각각 정수 i,s가 주어짐 (1 <= i <= N, 1 <= s <= 5)
이는 i번째 학생이 선호도를 s라고 응답함을 의미함
그 다음 k줄에 각각 정수 a,b가 주어짐
a와 b는 같지 않으며 이는 학생 a와 학생 b가 친구임을 의미함

출력: 선호도의 평균을 출력하라.
*/

//algorithm: BFS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_SIZE 100001
using namespace std;

int n, m, k;
int students[MAX_SIZE];
double ans = 0;
double divide;
bool visited[MAX_SIZE];
vector<int> map[MAX_SIZE];
queue<int> q;

int BFS(int node) {
	int output_cnt = 0;
	int output_sum = 0;
	memset(visited, false, sizeof(visited));
	visited[node] = true;
	if (map[node].size() == 0) {
		divide -= 1;
		return 0;
	}
	q.push(node);
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < map[top].size(); i++) {
			int next_node = map[top][i];
			if (visited[next_node]) continue;
			if (students[next_node] == -1) continue;
			visited[next_node] = true;
			q.push(next_node);
			output_cnt++;
			output_sum += students[next_node];
		}
	}
	return output_sum / output_cnt;
}

int main(void) {
	cin >> n >> m >> k;
	divide = n;
	for (int i = 1; i <= n; i++) {
		students[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		students[a] = b;
		ans += b;
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (students[i] == -1) {
			ans += BFS(i);
		}
	}
	printf("%.2lf", ans / divide);
	return 0;
}
