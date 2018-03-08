#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
//得到所有下标大于等于x的数贡献的逆序数
int getReverseNumber(vector<int>& A, int x)
{
    int cnt = 0;
    for (int i = x; i < A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[i]) cnt++;
        }
    }
    return cnt;
}
 
int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int k = 0; k <= K; k++)
        {
            vector<int> B1(A.begin(), A.begin() + i + 1);
            dp[i][k] = getReverseNumber(B1, i) + dp[i + 1][k];
            if (k > 0) {
                for (int l = i+1; l < n; l++)
                {
                    vector<int> B2(A.begin(), A.begin() + l + 1);
                    reverse(B2.begin() + i, B2.begin() + l + 1);
                    dp[i][k] = min(dp[i][k], getReverseNumber(B2, i) + dp[l + 1][k - 1]);
                }
            }
        }
    }
    cout << dp[0][K] << endl;
    return 0;
}