#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------ɨ����Ϸ------\n");
	for (j = 0;j <= col;j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <=col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------ɨ����Ϸ------\n");
}


void SetMine(char board[ROWS][COLS],int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}


int get_mine_count(char board[ROWS][COLS],int x,int y)
{
	return (board[x - 1][ y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0');
}


void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    // ��������߽���Ѿ�չ������ֱ�ӷ���
    if (x < 1 || x > ROW || y < 1 || y > COL || show[x][y] != '*')
        return;

    // ��ȡ��ǰ������Χ������
    int count = get_mine_count(mine, x, y);
    show[x][y] = count + '0'; // ��ʾ����

    // �����Χû���ף��ݹ�չ����Χ8������
    if (count == 0)
    {
        Expand(mine, show, x - 1, y - 1);
        Expand(mine, show, x - 1, y);
        Expand(mine, show, x - 1, y + 1);
        Expand(mine, show, x, y - 1);
        Expand(mine, show, x, y + 1);
        Expand(mine, show, x + 1, y - 1);
        Expand(mine, show, x + 1, y);
        Expand(mine, show, x + 1, y + 1);
    }
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//�ҵ��׵ĸ���
	while (win < row * col - EASY_COUNT)
	{
		printf("������Ҫ�Ų������:>");
		scanf("%d,%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("�������ѱ��Ų�\n");
			}
			else
			{
				//�������
				if (mine[x][y] == '1')
				{
					printf("���ź�,�㱻ը����\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				//���������
				else
				{
					win++;
					int count = get_mine_count(mine, x, y);//ͳ��mine�����x,y������Χ�м�����
					if (count == 0)
					{
						Expand(mine, show, x, y);
					}
					else
					{
						show[x][y] = count + '0';
					}
					DisplayBoard(show, ROW, COL);
				}
			}
		}
		else
		{
			printf("����Ƿ�,����������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ��,���׳ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}