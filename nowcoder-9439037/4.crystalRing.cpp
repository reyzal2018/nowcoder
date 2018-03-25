#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    vector<pair<int, int>> range;
    cin >> n >> m;
    range.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> range[i].first >> range[i].second;
    }
    //用i个珠子得到长度为j的手链的方案数
    long long dp[25][105] = {0};
    //只用一种珠子可以得到的方案数
    for (int i = range[0].first; i <= range[0].second; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= m; j++)
        {
            //用i颗珠子得到j的方案数
            for (int k = range[i-1].first; k <= j && k <= range[i-1].second; k++)
            {
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}