//解法一、代码①
#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

void calcAllPermutation(char* perm, int from, int to)
{
	if (to <= 1)
	{
		return;
	}

	if (from == to)
	{
		for (int i = 0; i <= to; i++)
			cout << perm[i];
		cout << endl;
	}
	else
	{
		for (int j = from; j <= to; j++)
		{
			swap(perm[j], perm[from]);
			calcAllPermutation(perm, from + 1, to);
			swap(perm[j], perm[from]);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[] = "abc";
	cout << a << "所有全排列的结果为：" << endl;
	calcAllPermutation(a, 0, 2);
	system("pause");
	return 0;
}


//解法二
template <typename T>
void CalcAllPermutation(T perm[], int num)
{
	if (num < 1)
		return;

	while (true)
	{
		int i;
		for (i = num - 2; i >= 0; --i)
		{
			if (perm[i] < perm[i + 1])
				break;
		}

		if (i < 0)
			break;  // 已经找到所有排列

		int k;
		for (k = num - 1; k > i; --k)
		{
			if (perm[k] > perm[i])
				break;
		}

		swap(perm[i], perm[k]);
		reverse(perm + i + 1, perm + num);

	}
}


//类似问题
//假设str已经有序，from 一直很安静  
void perm(char *str, int size, int resPos)  
{  
	if(resPos == size)  
		print(result);  
	else  
	{  
		for(int i = 0; i < size; ++i)  
		{  
			result[resPos] = str[i];  
			perm(str, size, resPos + 1);  
		}  
	}  
}  
