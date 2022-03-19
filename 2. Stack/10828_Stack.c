/*
백준 10828
*/

//Data Structure: Stack

#include <stdio.h>

int pointer = 0;
int stack[10001];

void push(int n){
	stack[pointer] = n;
	pointer++;
}

void pop(void){
	if(is_empty()) printf("-1\n");
	else{
		printf("%d\n",stack[pointer-1]);
		pointer--;
	}
}

void size(void){
	printf("%d\n",pointer);
}

void empty(void){
	printf("%d\n",is_empty());
}

int is_empty(void){
	if(pointer) return 0;
	return 1;
}

void top(void){
	if(is_empty()) printf("-1\n");
	else printf("%d\n",stack[pointer-1]);
}

int main(void) {
	int m;
	scanf("%d",&m);
	while(m--){
		char string[10];
		scanf("%s",string);
		if(strcmp("push",string) == 0){
			int n;
			scanf("%d",&n);
			push(n);
		}
		else if(strcmp("pop",string) == 0) pop();
		else if(strcmp("size",string) == 0) size();
		else if(strcmp("empty",string) == 0) empty();
		else if(strcmp("top",string) == 0) top();
	}
	return 0;
}
