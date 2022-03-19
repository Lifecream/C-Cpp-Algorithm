/*
백준 1476번
https://www.acmicpc.net/problem/1476
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void) {
	int e,s,m;
	scanf("%d %d %d",&e,&s,&m);
	int a=1,b=1,c=1;
	for(int i = 1;; i++){
		if(a==e && b==s && c==m){
			printf("%d",i);		
			return 0;
		}
		a++;
		if(a==16) a=1;
		b++;
		if(b==29) b=1;
		c++;
		if(c==20) c=1;
	}
	return 0;
}
