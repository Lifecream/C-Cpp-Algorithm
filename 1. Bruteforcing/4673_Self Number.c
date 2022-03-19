/*
백준 4673번
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void) {
	int a,b,sum;
	for(int i = 1; i<=10000; i++){
		a=0;
		for(int j = 1; j<i; j++){
			sum = j;
			b=j;
			while(b){
				sum += b % 10;
				b /= 10;
			}
			if(sum == i)
				a=1;
		}
		if(a!=1)
			printf("%d\n",i);
	}
	
	return 0;
}
