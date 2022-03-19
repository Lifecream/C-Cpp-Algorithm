/*
백준 14939번
https://www.acmicpc.net/problem/14939
*/

//algorithm: Bitmask

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_SIZE 11
#define INF 1 << 30
using namespace std;

bool map[MAX_SIZE][MAX_SIZE];
int dx[] = { 0, -1, 1, 0, 0 };	//0:center, 1:up, 2:down, 3:left, 4:right
int dy[] = { 0, 0, 0, -1, 1 };

void input(void) {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			char temp;
			cin >> temp;
			if (temp == 'O') map[i][j] = true;
			else map[i][j] = false;
		}
	}
}

void print_map(bool (*temp)[MAX_SIZE]) {
	for (int i = 1; i < MAX_SIZE; i++) {
		cout << '\n';
		for (int j = 1; j < MAX_SIZE; j++) {
			if (temp[i][j] == true) cout << 'O';
			else cout << '#';
		}
	}
}

bool check_map(bool(*temp)[MAX_SIZE]) {
	for (int i = 1; i < MAX_SIZE; i++) {
		if (!temp[10][i]) continue;
		return false;
	}
	return true;
}

void reverse(bool (*temp)[MAX_SIZE], int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == 0 || ny == 0 || nx == MAX_SIZE || ny == MAX_SIZE) continue;
		temp[nx][ny] = !temp[nx][ny];
	}
}

int following(bool (*selected)[MAX_SIZE], int initial) {
	int output = initial;	//output == counter
	for (int i = 2; i < MAX_SIZE; i++) {
		for (int j = 1; j < MAX_SIZE; j++) {
			if (!selected[i - 1][j]) continue;
			reverse(selected, i, j);
			output++;
		}
	}
	if (check_map(selected)) return output;
	else return -1;
}

int selecting(void) {
	int ans = -1;
	for (int i = 0; i < (1 << 10); i++) {
		int temp = i;
		int cnt = 0;
		bool cpymap[MAX_SIZE][MAX_SIZE];
		memcpy(cpymap, map, sizeof(cpymap));
		//print_map(cpymap);
		for (int j = 1; j < MAX_SIZE; j++, temp = temp >> 1) { //Bitmask
			if (temp % 2 == 0) continue;
			reverse(cpymap, 1, j);
			cnt++;
		}
		int result = following(cpymap, cnt);
		if (result == -1) continue;
		ans = result;
		break;
	}
	return ans;
}

int main(void) {
	input();
	cout << selecting();
	return 0;
}
