//编程题2 手串
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int m, n, c;
    cin >> n >> m >> c;
    vector<vector<int>> strings(n);
    vector<vector<int>> colors(c);
    for (size_t i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        strings[i].resize(k);
        for (size_t j = 0; j < k; j++)
        {
            cin >> strings[i][j];
			colors[strings[i][j] - 1].push_back(i + 1);
        }
    }
    int result = 0;
	for (auto& it : colors)
	{
		if (it.size() <= 1)
		{
			//01种颜色 不会冲突
			continue;
		}
		//检验环
		if (n - it[it.size() - 1] + it[0] < m) {
			result++;
			continue;
		}
		for (size_t i = 1; i < it.size(); i++)
		{
			if (it[i] - it[i - 1] < m) {
				result++;
				break;
			}
		}
	}
	cout << result << endl;
    return 0;
}
