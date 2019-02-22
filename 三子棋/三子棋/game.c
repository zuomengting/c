#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//��ӡĿ¼
void menu(){
	printf("////////////////////////////\n");
	printf("///1.��ʼ��Ϸ  0.������Ϸ///\n");
	printf("////////////////////////////\n");
}

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	} 
}

//��ӡ����
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

//�����
//�������X
//��������O
void PlayerMove(char board[ROW][COL], int row, int col){
	int x = 0;
	int y = 0;
	while (1){
		printf("��������ӣ�\n");
		scanf("%d%d", &x, &y);
		if ((x < row) && (x >= 0) && (y >= 0) && (y < col)){
			//��ȷ���ظ�
			if (board[x][y] == ' '){
				board[x][y] = 'X';
				break;
			}
			else{
				printf("�������Ѿ������ӣ����������룡\n");
			}
		}
		else{
			printf("����Ƿ������������룡\n");
		}
	}
}

//������
void ComputerMove(char board[ROW][COL], int row, int col){
	int x = 0;
	int y = 0;
	printf("��������\n");
	while (1){
		x = rand() % row ;
		y = rand() % col ; 
		if (board[x][y] == ' '){
				board[x][y] = 'O';
				break;
		}
	}
}


//�ж��Ƿ����������
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



//�ж���Ӯ
//���X
//����O
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