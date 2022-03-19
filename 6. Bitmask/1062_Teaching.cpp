/*
백준 1062번
https://www.acmicpc.net/problem/1062
*/

//algorithm: Bitmask

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k;
int ans;
char s[51][16];
bool Alphabet[26];

void Print(void) {
	for (int i = 0; i < 26; i++) {
		if (Alphabet[i]) cout << (char)(i + 97) << ' ';
	}
	cout << endl;
}

void checking(void) {
	int a = 0;
	//Print();
	for (int i = 0; i < n; i++) {
		int f = 1;
		for (int j = 0; j < strlen(s[i]); j++) {
			if (Alphabet[s[i][j] - 97]) continue;
			f = 0;
			break;
		}
		if (f) a++;
	}
	ans = max(ans, a);
}

void Combination(int index, int cnt, int default_setting) {
	if (cnt == 0) checking();
	if (cnt >= 5 && default_setting == 0) {
		Alphabet[0] = true;
		Alphabet[2] = true;
		Alphabet[8] = true;
		Alphabet[13] = true;
		Alphabet[19] = true;
		Combination(index, cnt - 5, 1);
	}
	else {
		for (int i = index; i < 26; i++) {
			if (!Alphabet[i]) {
				Alphabet[i] = true;
				Combination(i, cnt - 1, default_setting);
				Alphabet[i] = false;
			}
		}
	}
}

int main(void) {
	memset(Alphabet, false, sizeof(Alphabet));
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	Combination(0, k, 0);
	cout << ans;
	return 0;
}
