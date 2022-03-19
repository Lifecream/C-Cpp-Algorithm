/*
백준 1018번
https://www.acmicpc.net/problem/1018
*/

//algorithm: Bruteforcing

#include <stdio.h>

int main(void){
	char chess_board[50][50];
	int m,n;	//m 가로, n 세로 
	scanf("%d %d",&m,&n);
	for(int i = 0; i<m; i++){
		scanf("%s",chess_board[i]);
	}
	int cnt = 0;
	int min = -1;
	for(int h = 0; h<m-7; h++){	//모서리 세로 
		for(int w = 0; w<n-7; w++){	//모서리 가로 
			for(int b_or_w = 0; b_or_w < 2; b_or_w++){	//모서리 왼쪽 위가 검정인지 하양인지 
				for(int i = 0; i<8; i++){	        //모서리부터 8칸 세로 
					for(int j = 0; j<8; j++){	//모서리부터 8칸 가로 
						if(b_or_w == 0){
							if(i%2 == 0){
								if(j%2 == 0){
									if(chess_board[h+i][w+j] != 'B'){
										cnt++;
									}
								} 
								else{
									if(chess_board[h+i][w+j] != 'W'){
										cnt++;
									}
								}
							}
							else{
								if(j%2 == 0){
									if(chess_board[h+i][w+j] != 'W'){
										cnt++;
									}
								} 
								else{
									if(chess_board[h+i][w+j] != 'B'){
										cnt++;
									}
								}
							}
						}
						else{ //모서리 W 
							if(i%2 == 0){
								if(j%2 == 0){
									if(chess_board[h+i][w+j] != 'W'){
										cnt++;
									}
								} 
								else{
									if(chess_board[h+i][w+j] != 'B'){
										cnt++;
									}
								}
							}
							else{
								if(j%2 == 0){
									if(chess_board[h+i][w+j] != 'B'){
										cnt++;
									}
								} 
								else{
									if(chess_board[h+i][w+j] != 'W'){
										cnt++;
									}
								}
							}
						} 
					}
				}
				if(min == -1 || min > cnt)
					min = cnt;
				cnt = 0;
			}
		}
	}
	printf("%d",min);
	return 0;
}
