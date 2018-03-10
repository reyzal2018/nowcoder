#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
    cin >> n;
	vector<int> dp(101,0x3d3d3d3d);
	dp[6] = 1;
	dp[8] = 1;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] == 0x3d3d3d3d)
			continue;
		//当前点可以到哪些点
		for (int j = 6; j + i <= n; j += 6)
		{
			dp[j + i] = min(dp[i + j], dp[i] + j / 6);
		}
		for (int j = 8; j + i <= n; j += 8)
		{
			dp[j + i] = min(dp[i + j], dp[i] + j / 8);
		}
	}
	cout << (dp[n] == 0x3d3d3d3d ? -1 : dp[n]) << endl;
    return 0;
}