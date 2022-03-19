/*
백준 1977번
https://www.acmicpc.net/problem/1977
*/

//algorithm: Bruteforcing

#include <stdio.h>
#include <math.h>

int main(void) {
	int a,b;
	scanf("%d %d",&a,&b);
	int min = -1;
	int cnt = 0;
	for(int i = a; i<=b; i++){
		double x = i;
		int y = i;
		if(sqrt(x) == (int)sqrt(x)){
			cnt += i;
			if(min == -1) min = i;
		}
	}
	if(min == -1){
		printf("-1");
		return 0;
	}
	printf("%d\n%d",cnt,min);
	return 0;
}
