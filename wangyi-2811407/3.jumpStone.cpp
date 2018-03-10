#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, 0x7dddddd);
    dp[n] = 0;
    for (int i = n; i < m; i++)
    {
        if (dp[i] == 0x7dddddd) continue;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                if (i + j <= m)
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                if (i + i / j <= m)
                    dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
            }
        }
    }
    cout << ((dp[m] == 0x7dddddd) ? -1 : dp[m]) << endl;
    return 0;
}