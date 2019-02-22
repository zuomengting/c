#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//打印目录
void menu(){
	printf("////////////////////////////\n");
	printf("///1.开始游戏  0.结束游戏///\n");
	printf("////////////////////////////\n");
}

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	} 
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col - 1; j++){
			printf(" %c |",board[i][j]);
		}
		if (j = col - 1){
			printf(" %c ", board[i][j]);
		printf("\n");
		}
		if (i != row - 1){
			for (j = 0; j < col; j++){
				printf("---", board[i][j]);
				if (j != (col - 1)){
					printf("|");
				}
			}
			printf("\n");
		}
	}	
}

//玩家走
//玩家下子X
//电脑下子O
void PlayerMove(char board[ROW][COL], int row, int col){
	int x = 0;
	int y = 0;
	while (1){
		printf("请玩家落子：\n");
		scanf("%d%d", &x, &y);
		if ((x < row) && (x >= 0) && (y >= 0) && (y < col)){
			//正确与重复
			if (board[x][y] == ' '){
				board[x][y] = 'X';
				break;
			}
			else{
				printf("此坐标已经有棋子，请重新输入！\n");
			}
		}
		else{
			printf("坐标非法，请重新输入！\n");
		}
	}
}

//电脑走
void ComputerMove(char board[ROW][COL], int row, int col){
	int x = 0;
	int y = 0;
	printf("电脑落子\n");
	while (1){
		x = rand() % row ;
		y = rand() % col ; 
		if (board[x][y] == ' '){
				board[x][y] = 'O';
				break;
		}
	}
}


//判断是否把棋盘下满
int FullBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}



//判断输赢
//玩家X
//电脑O
char Win(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if (board[i][j] == board[i][j - 1] && board[i][j + 1] == board[i][j] && board[i][j] != ' '){
				return board[i][j];
			}
			else if (board[i][j] == board[i - 1][j] && board[i][j] == board[i + 1][j] && board[i][i] != ' ') {
				return board[i][j];
			}
			else if (board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i + 1][j + 1] && board[i][j] != ' '){
				return board[i][j];
			}
			else if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i + 1][j - 1] && board[i][j] != ' '){
				return board[i][j];
			}
		}
	}
		if (FullBoard(board, ROW, COL) == 1){
			return 'P';
		}
	return ' ';
}