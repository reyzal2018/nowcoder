#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        sum += height[i];
    }
    const int minValue = -0x3d3d3d3d;
    //dp[i][j] 摆了i块砖 高度差为j时低塔高度
    //dp[i][j] = dp[i-1][j] 不摆
    //           dp[i-1][j+h]+h 摆在低塔 仍为低塔
    //           dp[i-1][h-j]+h-j 摆在低塔 变为高塔
    //           dp[i-1][j-h] 摆在高塔 仍为高塔
    //求4个值的最大值
    vector<int> dpi(sum + 1, minValue);//dpi
    vector<int> dpi_1(dpi);//dp[i-1]
    int result = 0;
    dpi_1[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int h = height[i - 1];
        for (int j = 0; j < sum+1; j++)
        {
            dpi[j] = max(dpi_1[j], max(j + h <= sum ? dpi_1[j + h] + h : minValue, max(h - j >= 0 ? dpi_1[h - j] + h - j : minValue, j - h >= 0 ? dpi_1[j - h] : minValue)));
        }
        dpi_1 = dpi;
    }
    cout << (dpi[0] > 0 ? dpi[0] : -1) << endl;
    return 0;
}