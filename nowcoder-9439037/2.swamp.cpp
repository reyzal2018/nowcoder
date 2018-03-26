#include<bits/stdc++.h>

using namespace std;

struct Arc
{
	int b, e;
	int cost;
};

int main()
{
	//求最小生成树即可
	int N, M;
	cin >> N >> M;
	vector<Arc> data(M);
	//树的集合
	vector<vector<int>> tree(N);
	for (int i = 0; i < M; i++)
	{
		cin >> data[i].b >> data[i].e >> data[i].cost;
	}
	for (int i = 0; i < N; i++)
	{
		tree[i].push_back(i + 1);
	}
	sort(data.begin(), data.end(), [](Arc& c1, Arc& c2) {return c1.cost < c2.cost; });
	int longestWood = 0;
	for (int i = 0; i < M; i++)
	{
		int b = data[i].b;
		int e = data[i].e;
		int bIndex = -1;
		int eIndex = -1;
		for (int i = 0; i < N; i++)
		{
			if (find(tree[i].begin(),tree[i].end(),b) != tree[i].end())
			{
				bIndex = i;
			}
			if (find(tree[i].begin(), tree[i].end(), e) != tree[i].end())
			{
				eIndex = i;
			}
		}
		if (bIndex == eIndex)
		{
			//已经在同一个集合中
			continue;
		}
		tree[bIndex].insert(tree[bIndex].end(), tree[eIndex].begin(), tree[eIndex].end());
		tree[eIndex].clear();
		longestWood = max(longestWood, data[i].cost);
	}
	cout << longestWood << endl;
	return 0;
}