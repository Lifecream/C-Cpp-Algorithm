/*
백준 11279번
https://www.acmicpc.net/problem/11279
*/

//algorithm: Priority_Queue(Heap)

#include <iostream>
#include <algorithm>
#define ARRAYSIZE 100001

using namespace std;

int heap[ARRAYSIZE];
int cnt = 0;

void print_heap(void){
	cout << "Heap Size: " << cnt <<" [ ";
	int printing = 1;
	for(int j = 1; j<=cnt; j++){
		printing = 0;
		cout << heap[j] << ' ';
	}
	if(printing) cout << "Heap is Empty ";
	cout << ']' << '\n';
}

void swap(int a,int b){
	int temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void swap_input(int a, int b){
	swap(a,b);
	if(b != 1){
		if(heap[b] > heap[b/2]) swap_input(b,b/2);
	}
	return;
}

void push(int a){
	heap[++cnt] = a;
	//print_heap();
	if(cnt != 1){
		if(heap[cnt] > heap[cnt/2]){
			swap_input(cnt,cnt/2);
		}
	}
	return;
}

void remove(void){
	if(cnt == 0){
		printf("0\n");
		//print_heap();
		return;
	}
	printf("%d\n",heap[1]);
	heap[1] = heap[cnt--];
	//print_heap();
	int parent = 1;
	int target;
	while(parent <= cnt){
		if(parent * 2 <= cnt){
			target = parent * 2;
			if(target + 1 <= cnt) target = heap[target] <= heap[target+1] ? target+1 : target;
			if(heap[parent] < heap[target]){
				swap(parent,target);
				parent = target;
				continue;
			}
		}
		break;
	}
	return;
}

int main(void) {
	heap[0] = 0;
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		int input;
		scanf("%d",&input);
		if(!input) remove();
		else push(input);
		//print_heap();
	}
	return 0;
}
