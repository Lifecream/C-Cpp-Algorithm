/*
백준 1912번
https://www.acmicpc.net/problem/1912
*/

//algorithm: Dynamic_Programming

#include <iostream>

using namespace std;

int main(void) {
	int n;
	int array[100000];
	cin >> n;
	for(int i = 0 ; i<n; i++){
		cin >> array[i];
	}
	int max = array[0];
	for(int i = 1; i<n; i++){
		if(array[i-1] >= 0 && array[i-1] + array[i] >= 0){
			array[i] = array[i] + array[i-1];
		}
		if(max < array[i]){
			max = array[i];
		}
	}
	cout << max;
	return 0;
}
