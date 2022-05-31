/*
백준 1517번
https://www.acmicpc.net/problem/1517
*/

//algorithm: Segment Tree

#include <iostream>
#include <algorithm>
#define MAX_SIZE 500001

using namespace std;

int n;
int arr[MAX_SIZE];
int sorted[MAX_SIZE];
long long ans = 0;

void input(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
}

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	int cnt = 0;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k++] = arr[i++];
			ans += (long long)cnt;
		}
		else {
			sorted[k++] = arr[j++];
			cnt++;
		}
	}
	if (i > mid) {
		while (j <= end) {
			sorted[k++] = arr[j++];
			cnt++;
		}
	}
	else {
		while (i <= mid) {
			sorted[k++] = arr[i++];
			ans += (long long)cnt;
		}
	}
	for (int index = start; index <= end; index++) arr[index] = sorted[index];
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, end);
	}
}

int main(void) {
	input();
	merge_sort(1, n);
	//for (int i = 1; i <= n; i++) cout << sorted[i] << ' ';
	cout << ans;
	return 0;
}
