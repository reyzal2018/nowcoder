#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> data(n),a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        a[i] = data[i] / 1024;
        sum += a[i];
    }
    int m = sum / 2;
    //背包问题 dp[i][j]用j个数得到最接近i的结果
    vector<vector<int>> dp(m + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < m + 1; i++) {
        dp[i][0] = i >= a[0] ? a[0] : 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], i >= a[j] ? dp[i - a[j]][j - 1] + a[j] : 0));
        }
    }
    int sub = m - dp[m][n - 1];
    cout << (m + sub + sum % 2) * 1024 << endl;
    return 0;
}