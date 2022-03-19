/*
백준 2501번
https://www.acmicpc.net/problem/2501
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void){
	int a,b,cnt = 0;
	scanf("%d %d",&a,&b);
	for(int i = 1; i<=a; i++){
		if(a%i == 0) cnt++;
		if(cnt == b){
			printf("%d",i);
			return 0;
		}
	}
	printf("0");
    return 0;
}
