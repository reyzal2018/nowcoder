#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
int main()
{
    string s1, s2;
    char buf[51];
    cin.getline(buf, 51);
    s1.assign(buf);
    cin.getline(buf, 51);
    s2.assign(buf);
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    int result = 0;
    for (size_t i = 1; i <= s1.length(); i++)
    {
        for (size_t j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    cout << result << endl;
    return 0;
}