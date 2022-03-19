/*
백준 11723번
https://www.acmicpc.net/problem/11723
*/

//algorithm: Bitmask

#include <stdio.h>

int set[21] = {0,};

void add(int n){
	set[n] = 1;
}

void r(int n){
	set[n] = 0;
}

void toggle(int n){
	if(set[n]) set[n] = 0;
	else set[n] = 1;
}

void all(void){
	for(int i = 1; i<21; i++) set[i] = 1;
} 

void empty(void){
	for(int i = 1; i<21; i++) set[i] = 0;
}

int main(void) {
	int m;
	scanf("%d",&m);
	while(m--){
		char string[10];
		int n;
		scanf("%s %d",string,&n);
		if(strcmp("add",string) == 0) add(n);
		else if(strcmp("remove",string) == 0) r(n);
		else if(strcmp("toggle",string) == 0) toggle(n);
		else if(strcmp("all",string) == 0) all();
		else if(strcmp("empty",string) == 0) empty();
		else printf("%d\n",set[n]);
	}
	return 0;
}
