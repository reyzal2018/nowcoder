#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

//在count里 从i到j变为连续 需要的最小操作次数
int getMinSum(int i, int j, int* count) {
	//相等 返回0
	if (i == j)
		return 0;
	//相邻 返回对应出现位置之差
	if (i == j - 1)
		return count[j] - count[i] - 1;
	else
		//其他，得到i+1,j-1需要的最少次数
		//加上使count[j]和count[i]连续需要的次数
		//(count[j] - count[i]) - (j - i) 说明:(count[j] - count[i])-1 表示将i j相邻需要的移动次数 
		//事实上他们需要相隔 j-i-1个元素 所以最终结果是(count[j] - count[i])-1-(j-i-1)
		return getMinSum(i + 1, j - 1, count) + (count[j] - count[i]) - (j - i);
}

int main()
{
	string s;
	int num;
	cin >> s >> num;
	map<char, vector<int>> mapCount;
	for (size_t i = 0; i < s.length(); i++)
	{
		mapCount[s[i]].push_back(i);
	}
	int result = 1;
	for (auto& it : mapCount) {
		int n = it.second.size();
		//只出现了一次 不需要计算
		if (n <= 1) continue;
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				if (getMinSum(i,j,&it.second[0]) <= num)
				{
					result = max(result, j - i + 1);
				}
			}
		}
	}
	cout << (s.length() == 0 ? 0 : result) << endl;
	return 0;
}
