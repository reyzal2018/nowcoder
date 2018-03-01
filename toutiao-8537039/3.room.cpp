//附加题
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> pi(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pi[i];
        pi[i] --;
    }
    vector<long long> dp(n + 1, 0);
    //开始时在第一个房间
    dp[0] = 0;
    //第二个房间等于第一个房间走一步到pi,再从pi走到第一个房间，然后再走一步。
    for (size_t i = 0; i < n; i++)
    {
        dp[i + 1] = dp[i] + 1 + dp[i] - dp[pi[i]] + 1;
        dp[i + 1] = (dp[i + 1] + 1000000007) % 1000000007;
    }
    cout << dp[n] << endl;
    return 0;
}