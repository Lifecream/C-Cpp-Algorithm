/*
백준 9012번
https://www.acmicpc.net/problem/9012
*/

//algorithm: Stack

#include <stdio.h>

int main(void) {
	int m;
	scanf("%d",&m);
	while(m--){
		int p = 0;
		char vps[51];
		scanf("%s",vps);
		if(vps[0] == ')' || vps[strlen(vps)-1] == '('){
			printf("NO\n");
			continue;
		}
		int break_all_for = 0;
		for(int i = 0; i<strlen(vps); i++){
			if(vps[i] == '(') p++;
			else p--;
			if(p < 0){
				printf("NO\n");
				break_all_for = 1;
				break;
			}
		}
		if(break_all_for) continue;
		if(p == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
