#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> input(n);
		map<int,int> indexMap;
		queue<int> q;
		for (int i = 0; i < n; i++)
		{
			input[i] = i;
			q.push(i);
		}
		int c = 0;
		//获取映射序列
		while (!q.empty())
		{
			q.push(q.front());
			q.pop();
			indexMap[q.front()] = ++c;
			q.pop();
		}
		for(auto& it:indexMap)
		{
			cout << it.second << (it.first == n - 1 ? "\n" : " ");
		}
	}
	return 0;
}