#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
 
using namespace std;
 
 
int main()
{
    string s;
    while (cin >> s) {
        string sr(s);
        reverse(sr.begin(), sr.end());
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, 0));
        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= sr.length(); j++)
            {
                if (s[i-1] == sr[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << s.length() - dp[s.length()][s.length()] << endl;
    }
    return 0;
}