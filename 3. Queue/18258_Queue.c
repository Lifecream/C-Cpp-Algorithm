/*
백준 108258번
*/

//algorithm: Queue

#include <stdio.h>
#include <string.h>

//push X: 정수 X를 큐에 넣는 연산이다.
//pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 큐에 들어있는 정수의 개수를 출력한다.
//empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
//front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

int queue[2000000];
int front_pointer = 0;
int back_pointer = 0;

void push(int x){
	queue[back_pointer] = x;
	back_pointer++;
}

void pop(void){
	if(is_empty()) printf("-1\n");
	else{
		printf("%d\n",queue[front_pointer]);
		front_pointer++;
	}
}

void size(void){
	printf("%d\n",back_pointer - front_pointer);
}

int is_empty(void){
	if(back_pointer - front_pointer == 0) return 1;
	return 0;
}

void empty(void){
	printf("%d\n",is_empty());
}

void front(void){
	if(is_empty()) printf("-1\n");
	else printf("%d\n",queue[front_pointer]);
}

void back(void){
	if(is_empty()) printf("-1\n");
	else printf("%d\n",queue[back_pointer-1]);
}

int main(void) {
	int n;
	scanf("%d",&n);
	while(n--){
		char string[10];
		scanf("%s",string);
		if(strcmp(string,"push") == 0){
			int x;
			scanf("%d",&x);
			push(x);
		}
		else if(strcmp(string,"pop") == 0) pop();
		else if(strcmp(string,"size") == 0) size();
		else if(strcmp(string,"empty") == 0) empty();
		else if(strcmp(string,"front") == 0) front();
		else if(strcmp(string,"back") == 0) back();
	}
	return 0;
}
