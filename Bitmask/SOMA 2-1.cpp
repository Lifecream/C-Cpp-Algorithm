/*
SW 마에스트로 코딩테스트 2차 1번 문제
N명의 손님, M개의 메뉴, K개의 제거할 메뉴
손님은 선호도가 5보다 높은 메뉴가 없으면 찾아오지 않음
메뉴 K개를 제거했을 때 찾아오는 손님 수

입력: 첫줄에 n,m,k
이어지는 2~n+1 줄까지 각 손님 별로 메뉴의 선호도(0~9)가 주어짐

출력: K개를 제거 하고 찾아올 수 있는 손님의 최대 값
*/

//algorithm: Bitmask

#include <iostream>
#include <algorithm>
#include <cstring>
#define N_SIZE 1001
#define M_SIZE 17

using namespace std;

int n, m, k;
int people[N_SIZE][M_SIZE];
int ans = -1;
bool visited[M_SIZE];

void Combination(int p, int q, int dp) {
	if (q != 0) {
		for (int i = p; i < m; i++) {
			int select = (1 << i);
			//cout << select << endl;
			if (dp & (1 << i)) continue;
			Combination(i + 1, q - 1, dp | (1 << i));
		}
	}
	else {
		bool menu[M_SIZE];
		bool consumer[N_SIZE];
		memset(consumer, false, sizeof(true));
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			//cout << dp % 2;
			if (dp % 2) menu[i] = false;
			else menu[i] = true;
			dp = dp >> 1;
		}
		//cout << endl;
		for (int i = 0; i < n; i++) {
			bool flag = false;
			for (int j = 0; j < m; j++) {
				if (!menu[j]) continue;
				//printf("people[%d][%d] = %d\n",i,j,people[i][j]);
				if (people[i][j] >= 5) {
					flag = true;
					break;
				}
			}
			if (flag) cnt++;
		}
		if (ans == -1 || ans < cnt) ans = cnt;
	}
}

int main(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> people[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
	Combination(0, k, 0);
	cout << ans;
	return 0;
}
