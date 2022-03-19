/*
백준 10773번
https://www.acmicpc.net/problem/10773
*/

//algorithm: Stack

#include <stdio.h>

int pointer = 0;
int stack[1000000];

void push(int n){
	stack[pointer] = n;
	pointer++;
}

void pop(void){
	pointer--;
}

int main(void) {
	int m;
	scanf("%d",&m);
	while(m--){
		int n;
		scanf("%d",&n);
		if(n) push(n);
		else pop();
	}
	int sum = 0;
	for(int i = 0; i<pointer; i++){
		sum += stack[i];
	}
	printf("%d",sum);
	return 0;
}
