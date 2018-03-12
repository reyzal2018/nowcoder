#include <bits/stdc++.h>

using namespace std;

void multipy(vector<vector<int>>& mat1, vector<vector<int>> mat2)
{
	vector<vector<int>> tmp(mat1);
	for (int i = 0; i < mat1.size(); i++)
	{
		for (int j = 0; j < mat2.size(); j++)
		{
			mat1[i][j] = 0;
			for (int k = 0; k < mat1.size(); k++)
			{
				mat1[i][j] += tmp[i][k] * mat2[k][j];
			}
			mat1[i][j] %= 100;
		}
	}
}

void calc(vector<vector<int>>& mat,int k)
{
	vector<vector<int>> res(mat.size(), vector<int>(mat.size(), 0));
	for (int i = 0; i < res.size(); i++)
	{
		res[i][i] = 1;
	}
	while (k)
	{
		if (k & 1) {
			multipy(res, mat);
		}
		k >>= 1;
		if(k) multipy(mat, mat);
	}
	mat = res;
}


/*
假设n=3 颜色矩阵B
1 0 1
1 1 0
0 1 1
结果就是 B*(A^k) 核心就是求矩阵的k次幂
*/
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> data(n);
	vector<vector<int>> mat(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		mat[i][i] = 1;
		if (i + 1 == n)
			mat[0][i] = 1;
		else
			mat[i+1][i] = 1;
	}
	//求mat的k次方
	calc(mat, k);
	vector<int> tmp(data);
	for (int i = 0; i < data.size(); i++)
	{
		data[i] = 0;
		for (int j = 0; j < mat.size(); j++)
		{
			data[i] += tmp[j] * mat[j][i];
		}
		cout << data[i] % 100 << (i == data.size() - 1 ? "\n" : " ");
	}
	return 0;
}