/*
백준 1094번
https://www.acmicpc.net/problem/1094
*/

//algorithm: Bitmask

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	if (n == 64) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i < 64; i++) {
		int temp = i;
		int cnt = 0;
		int square = 0;
		int sum = 0;
		while (temp) {
			if (temp % 2) {
				sum += pow(2, square);
				cnt++;
			}
			square++;
			temp /= 2;
		}
		if (sum == n) {
			cout << cnt;
			break;
		}
	}
	return 0;
}
