/*
백준 1966번
https://www.acmicpc.net/problem/1966
*/

//algorithm: Queue

#include <stdio.h>

int queue[20000];
int front_pointer = 0;
int back_pointer = 0;

void push(int x){
    queue[back_pointer] = x;
    back_pointer++;
}

int pop(void){
    front_pointer++;
    return queue[front_pointer-1];
}

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        front_pointer = 0;
        back_pointer = 0;
        for(int i = 0; i<n; i++){
            int a;
            scanf("%d",&a);
            push(a);
        }
        int count = 0;
        while(1){
        	int f = 0;
            for(int i = front_pointer+1; i<back_pointer; i++){
            	if(queue[front_pointer] < queue[i]){
            		f = 1;
            		if(front_pointer == m) m = back_pointer;
            		push(pop());
            		break;
				}
			}
			if(f == 0){
				count++;
				if(front_pointer == m){
					printf("%d\n",count);
					break;
				}
				front_pointer++;
			}
        }
    }
    return 0;
}
