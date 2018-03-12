#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s;
    int n;
    cin >> s >> n;
    //dp[i][j]表示字符串长度i，余数为j时的结果数目
    vector<long long> dpi(n, 0);//dpi
    dpi[0] = 1;
    for (int i = 0; i < s.length(); i++)
    {
        vector<long long> dpi1(n, 0);//dp[i+1]
        char ch = s[i];
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (ch == 'X' || ch == k + '0')
                {
                    //当前余数会贡献 j * 10 + k%n的结果
                    dpi1[(j * 10 + k) % n] += dpi[j];
                }
            }
        }
        dpi = dpi1;
    }
    cout << dpi[0] << endl;
    return 0;
}