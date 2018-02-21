//在一个N*N矩阵的左上角坐着一个机器人，它只能向右运动或向下运动。
//那么， 机器人运动到右下角一共有多少种可能的路径？
//进一步地，
//如果对于其中的一些格子，机器人是不能踏上去的。设计一种算法来获得所有可能的路径。

#include <stdio.h>
//path(i, j) = path(i-1, j) + path(i, j-1)
int path(int m,int n)
{
	if(m < 1 || n < 1)
		return -1;
	if(m == 1 || n ==1)
		return 1;

	return path(m - 1, n) + path(m, n - 1);
}

int main()
{
	printf("%d\n", path(2, 2));
	printf("%d\n", path(3, 3));
	printf("%d\n", path(4, 4));
}