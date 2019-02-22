#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game(){
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	char tmp = 0;
	while (1){
		PlayerMove(board, ROW, COL);
		tmp = Win(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (tmp != ' '){
			break;
		}
		ComputerMove(board, ROW, COL);
		tmp = Win(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (tmp != ' '){
			break;
		}	
	}
	if (tmp == 'X'){
		printf("玩家获胜！\n");
	}
	if (tmp == 'O'){
		printf("电脑获胜，你输了！\n");
	}
	if (tmp == 'P'){
		printf("平局！\n");
	}
}
int main(){ 
	int n = 0;
	srand((unsigned int) time(NULL));
	do{
		menu();
		printf("输入你的选择:");
		scanf("%d", &n);
		switch (n){
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！");
			break;
		default:
			printf("非法输入，请重新选择！");
			break;
		}
	} while (n);
	system("pause");
	return 0;
}