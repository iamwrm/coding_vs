/* GNU gcc compiler on windows 10 x64 platform
mingw32  gcc version 4.9.2
-std=c++11
MIT License
Copyright (c) 2016 <iamwrm>
<author>           <version>           <date>                   <change>
iamwrm 				1.0              2016-11-20              完成画一个正方体
iamwrm			    1.1              2016-11-21              完成，但是两个连起来的凹陷处中间依然有分隔
iamwrm				1.2				 2016-11-25			     优化了一下打印函数，避免打印空行


description: 打印 3*3 的方块
keywords:   文件操作

*/
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <string.h>

// 输出文件前的字符数组的长宽
#define FILE_ROW 500
#define FILE_COL 35
#define width 6
#define ini_y 200

void plot_one_cube(int x, int y, char arr[][FILE_COL])
{

	// line 0
	if (arr[y][x] == ' ')
		arr[y][x] = '_';
	for (int i = 1; i < width + 1; i++)
	{

		arr[y][x + i] = '_';
	}

	//line 1~3
	for (int dev = 0; dev < 3; dev++)
	{
		/*if (dev == 2)
		{
		if (arr[y + 1 + dev][x - 1 - dev] == ' ')
		arr[y + 1 + dev][x - 1 - dev] = '/';
		}
		else
		{
		arr[y + 1 + dev][x - 1 - dev] = '/';
		}*/
		arr[y + 1 + dev][x - 1 - dev] = '/';

		for (int i = 0; i < width; i++)
		{
			if (dev == 3 - 1)
				arr[y + 1 + dev][x + i - dev] = '_';
			else
				arr[y + 1 + dev][x + i - dev] = ' ';
		}
		arr[y + 1 + 1][x + width] = ' ';
		arr[y + 1 + dev][x + width - dev] = '/';
		arr[y + 1 + dev][x + width + 1] = '|';
		arr[y + 1 + 2][x + width] = ' ';
		arr[y + 1 + 2][x + width - 1] = ' ';
	}

	//line 4~6
	for (int dev = 3; dev < 6; dev++)
	{

		arr[y + 1 + dev][x - 3] = '|';
		for (int i = 0; i < width; i++)
		{
			if (dev == 6 - 1)
				arr[y + 1 + dev][x - 3 + 1 + i] = '_';
			else
				arr[y + 1 + dev][x - 3 + 1 + i] = ' ';
		}
		arr[y + 1 + dev][x + width - 2] = '|';
		arr[y + 1 + dev][x + width + 1 - dev + 3] = '/';

		arr[y + 1 + 3][x + width - 1] = ' ';
		arr[y + 1 + 3][x + width] = ' ';
		arr[y + 1 + 4][x + width - 1] = ' ';
	}
}

void writein(FILE *fp, char arr[][FILE_COL])
{
	for (int i = 0; i < FILE_ROW; i++)
	{
		int isthing =0;
		for (int j = 0; j < FILE_COL; j++)
		{
			if (arr[i][j] != ' ') isthing = 1;
		}
		if (isthing == 1)
		{
			for (int j = 0; j < FILE_COL; j++)
			{

				if (i == FILE_ROW - 1)
				{
					fprintf(fp, " ");
					printf(" ");
				}
				else
				{
					fprintf(fp, "%c", arr[i][j]);
					printf("%c", arr[i][j]);
				}
			}
			fprintf(fp, "\n");
			printf("\n");
		}
	}
}


int main()
{
	//define file handle
	FILE *fp;
	fp = fopen("testout.txt", "w+");

	//初始化输出文件前的字符数组
	char arr[FILE_ROW][FILE_COL];
	for (int i = 0; i < FILE_ROW; i++)
	{
		for (int j = 0; j < FILE_COL; j++)
		{
			arr[i][j] = ' ';
		}
	}



	int matin[3][3] = {
		3 ,3, 3, 1, 0, 1, 1, -3, 1 };

	//[y][x]      x  y   第y行 第x列
	// plot_one_cube(20, 15, arr);
	int i, j, k;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			int temp = matin[i][j];

			if (temp >= 0)
				for (k = 0; k < temp; k++)
				{
					plot_one_cube(13 + 7 * j - 3 * i, ini_y - 3 * k + 3 * i, arr);
				}
			else
			{
				for (k = 0; k < -temp; k++)
				{
					plot_one_cube(13 + 7 * j - 3 * i, ini_y - 3 * k + 3 * i - 3 * temp, arr);
				}
			}
			// writein(fp, arr);
		}
	}

	// 将数组写入txt
	writein(fp, arr);
	// getchar();
	//close file
	fclose(fp);
	return 0;
}
