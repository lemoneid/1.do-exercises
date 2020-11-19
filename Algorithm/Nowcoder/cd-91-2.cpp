/*************************************************************************
	> File Name: cd-91-2.cpp
	> Author: yanzhiwei 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年11月14日 星期六 21时01分54秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;
//一般的递归法和动态规划方法，左神的书已经讲的比较清楚
//这里主要说一说另一种思路
//设胜者的总分为x,败者的总分为y，且有 x - y = diff; //方程一
//又因为两者的分数和为纸牌的总分，则有 x + y = sum; //方程二
//联立方程式可得 x = (sum + diff)/2;
//因此题目就转化为求两者的总分差diff
//令递推公式f(i,j):在剩余的i~j牌中,A(先拿)的分数减去B(后拿)的分数
//因此 f(i,j)=max(arr[i]-f(i+1,j),arr[j]-f(i,j-1));
//上式中的f(i+1,j)为剩余牌中B的分数减去A的分数,加负号并加上arr[i],
//代表A取最左边牌的情况，arr[j]-f(i,j-1)的含义为取最右的情况

//根据递推公式直接递归的方法
//diff = first - second
int getDiffCore(const int *arr, int i, int j);

int winner_Solution3_Recursive(const int arr[], const int len)
{
	if (arr == NULL || len < 1)
		return 0;

	int sum = 0;
	for (int i = 0; i < len; ++i)
		sum += arr[i];

	int diff = getDiffCore(arr, 0, len - 1);
	if (diff < 0)
		diff = -diff;

	return (sum + diff) / 2;
}

int getDiffCore(const int *arr, int i, int j)
{
	if (i == j)
		return arr[i];

	return std::max(arr[i] - getDiffCore(arr, i + 1, j), arr[j] - getDiffCore(arr, i, j - 1));
}

//===================================
//一般的动态规划
int winner_Solution3(const int arr[], const int len)
{
	if (arr == NULL || len < 1)
		return 0;

	int sum = 0;
	for (int i = 0; i < len; ++i)
		sum += arr[i];

	int **f = make2DArray<int>(len, len);
	for (int j = 0; j < len; ++j)
	{
		f[j][j] = arr[j];
		for (int i = j - 1; i >= 0; --i)
		{
			f[i][j] = std::max(arr[i] - f[i + 1][j], arr[j] - f[i][j - 1]);
		}
	}

	int diff = f[0][len - 1];
	if (diff < 0)
		diff = -diff;

	return (sum + diff) / 2;
}

//================================
//空间压缩后，空间复杂度为O(N)
int winner_Solution3(const int arr[], const int len)
{
	if (arr == NULL || len < 1)
		return 0;

	int sum = 0;
	for (int i = 0; i < len; ++i)
		sum += arr[i];

	int *dp = new int[len];
	for (int i = len - 1; i >= 0; --i)
	{
		dp[i] = arr[i];
		for (int j = i + 1; j < len; ++j)
		{
			dp[j] = std::max(arr[i] - dp[j], arr[j] - dp[j - 1]);
		}
	}

	int diff = dp[len - 1];
	if (diff < 0)
		diff = -diff;

	
	return (sum + diff) / 2;
}


