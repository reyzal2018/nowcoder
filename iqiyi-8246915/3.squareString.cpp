#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(string s1, string s2) {
	vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[s1.length()][s2.length()];
}

int main()
{
	string s;
	cin >> s;
	int maxLen = 0;
	for (int i = 0; i < s.length(); i++)
	{
		maxLen = max(maxLen, lcs(string(s.begin(), s.begin() + i + 1), string(s.begin() + i + 1, s.end())));
	}
	cout << maxLen * 2 << endl;
	return 0;
}