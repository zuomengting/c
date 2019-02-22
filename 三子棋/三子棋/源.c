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
		printf("��һ�ʤ��\n");
	}
	if (tmp == 'O'){
		printf("���Ի�ʤ�������ˣ�\n");
	}
	if (tmp == 'P'){
		printf("ƽ�֣�\n");
	}
}
int main(){ 
	int n = 0;
	srand((unsigned int) time(NULL));
	do{
		menu();
		printf("�������ѡ��:");
		scanf("%d", &n);
		switch (n){
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;
		default:
			printf("�Ƿ����룬������ѡ��");
			break;
		}
	} while (n);
	system("pause");
	return 0;
}