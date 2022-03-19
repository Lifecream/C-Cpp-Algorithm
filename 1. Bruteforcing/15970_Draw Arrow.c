/*
백준 15970번
https://www.acmicpc.net/problem/15970
*/

//algorithm: Bruteforcing

#include <stdio.h>
#include <math.h>

int main(void) {
	int point[5000][3] = {0,};
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf("%d %d",&point[i][0],&point[i][1]);
	}
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			if(point[i][1] != point[j][1]) continue;
			if(point[i][2] == 0 || point[i][2] > abs(point[i][0] - point[j][0]))
				point[i][2] = abs(point[i][0] - point[j][0]); 
			if(point[j][2] == 0 || point[j][2] > abs(point[i][0] - point[j][0]))
				point[j][2] = abs(point[i][0] - point[j][0]); 
		}
	}
	int sum = 0;
	for(int i = 0; i<n; i++){
		sum += point[i][2];
	}
	printf("%d",sum);
	return 0;
}
