#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int* v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int p = max(i, j) + 1;
            dp[i][j] = 0x7fffffff;
            dp[i][j] = min(dp[i][j], dp[i][p] + (j == 0 ? 0 : abs(v[p - 1] - v[j - 1])));
            dp[i][j] = min(dp[i][j], dp[p][j] + (i == 0 ? 0 : abs(v[p - 1] - v[i - 1])));
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
