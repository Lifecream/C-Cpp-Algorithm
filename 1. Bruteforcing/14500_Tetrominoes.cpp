/*
백준 14500번
https://www.acmicpc.net/problem/14500
*/

//algorithm: Bruteforcing

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n,m;
	int paper[500][500];
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin >> paper[i][j];
		}
	}
	int biggest = 0;
	//case1
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j<m-2; j++){
			int four = paper[i][j+2] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
			int five = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
			int eight = paper[i+1][j] + paper[i][j] + paper[i][j+1] + paper[i][j+2];
			int nine = paper[i+1][j+2] + paper[i][j] + paper[i][j+1] + paper[i][j+2];
			int fourteen = paper[i+1][j] + paper[i+1][j+1] + paper[i][j+1] + paper[i][j+2];
			int fifteen = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j+2];
			int sixteen = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i+1][j+1];
			int eighteen = paper[i][j+1] + paper[i+1][j] + paper[i+1][j+1] + paper[i+1][j+2];
			biggest = max(biggest,max(max(max(max(max(max(max(four,five),eight),nine),fourteen),fifteen),sixteen),eighteen));
		}
	}
	//case2
	for(int i = 0; i<n-2; i++){
		for(int j = 0; j<m-1; j++){
			int six = paper[i][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];
			int seven = paper[i][j] + paper[i][j+1] + paper[i+1][j] + paper[i+2][j];
			int ten = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+2][j+1];
			int eleven = paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1] + paper[i+2][j];
			int twelve = paper[i][j] + paper[i+1][j] + paper[i+1][j+1] + paper[i+2][j+1];
			int thirteen = paper[i][j+1] + paper[i+1][j+1] + paper[i+1][j] + paper[i+2][j];
			int seventeen = paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1] + paper[i+2][j+1];
			int nineteen = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+1][j+1];
			biggest = max(biggest,max(max(max(max(max(max(max(six,seven),ten),eleven),twelve),thirteen),seventeen),nineteen));
		}
	}
	//case3
	for(int i = 0; i<n-3; i++){
		for(int j = 0; j<m; j++){
			int one = paper[i][j] + paper[i+1][j] + paper[i+2][j] + paper[i+3][j];
			biggest = max(biggest,one);
		}
	}
	//case4
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m-3; j++){
			int two = paper[i][j] + paper[i][j+1] + paper[i][j+2] + paper[i][j+3];
			biggest = max(biggest,two);
		}
	}
	//case5
	for(int i = 0; i<n-1; i++){
		for(int j = 0; j<m-1; j++){
			int three = paper[i][j] + paper[i+1][j] + paper[i][j+1] + paper[i+1][j+1];
			biggest = max(biggest,three);
		}
	}
	cout << biggest;
	return 0;
}
