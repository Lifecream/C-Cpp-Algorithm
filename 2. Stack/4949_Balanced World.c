/*
백준 4949번
https://www.acmicpc.net/problem/4949
*/

//algorithm: Stack

#include <stdio.h>
#include <string.h>

int stack[101];
int pointer = 0;

void push(int n){
	stack[pointer] = n;
	//printf("push: stack[%d] = %d\n",pointer,n);
	pointer++;
}

int pop(int n){
	if(stack[pointer-1] != n || pointer == 0){
		return 0;
	}
	stack[pointer] = 0;
	//printf("pop: stack[%d] = %d\n",pointer,n);
	pointer--;
	return 1;
}

int main(void){
	while(1){
		char string[101];
		gets(string);
		if(strlen(string) == 1 && string[0] == '.') break;
		int reset = 0;
		for(int i = 0; i<strlen(string); i++){
			if(string[i] == '(') push(1);
			else if(string[i] == '[') push(2);
			else if(string[i] == ')'){
				if(pop(1) == 0){
					printf("no\n");
					reset = 1;
					break;
				}
			}
			else if(string[i] == ']'){
				if(pop(2) == 0){
					printf("no\n");
					reset = 1;
					break;
				}
			}
		}
		if(reset){
			pointer = 0;
			continue;
		}
		if(pointer == 0) printf("yes\n");
		else printf("no\n");
		pointer = 0;
	}
	return 0;
}
