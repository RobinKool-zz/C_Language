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
	printf("------扫雷游戏------\n");
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
	printf("------扫雷游戏------\n");
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
    // 如果超出边界或已经展开过，直接返回
    if (x < 1 || x > ROW || y < 1 || y > COL || show[x][y] != '*')
        return;

    // 获取当前格子周围的雷数
    int count = get_mine_count(mine, x, y);
    show[x][y] = count + '0'; // 显示雷数

    // 如果周围没有雷，递归展开周围8个格子
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
	int win = 0;//找到雷的个数
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d,%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已被排查\n");
			}
			else
			{
				//如果是雷
				if (mine[x][y] == '1')
				{
					printf("很遗憾,你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				//如果不是雷
				else
				{
					win++;
					int count = get_mine_count(mine, x, y);//统计mine数组的x,y坐标周围有几个雷
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
			printf("坐标非法,请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你,排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}