#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
	//dp[i] 表示暗黑字符串数目
	//S[i] 表示i长度的字符串最后两位是相同字母的数目
	//D[i] 表示i长度的字符串最后两位是不同字幕的数目
	//最后两位相同，无论新字母是什么 都是暗黑 一共三种情况，此外，如果新字母和最后一个字母相同，则新的字符串最后两位仍然是相同的，有1种情况
	//最后两位不同，新字母如果和前两位不同，则不是暗黑，所以有两种情况是暗黑的。此外，如果新字母和最后一个字母相同，则新字符串是S的情况，有1中情况
	//S[i] = S[i-1]+D[i-1]=dp[i-1]
	//dp[i] = 3*S[i-1] + 2*D[i-1] =dp[i-1]*2+S[i-1]=dp[i-1]*2+dp[i-2]
	while (cin >> n) {
		vector<long long> dp(n + 1, 0);
		dp[1] = 3;
		dp[2] = 9;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 1] * 2 + dp[i - 2];
		}
		cout << dp[n] << endl;
	}
    return 0;
}