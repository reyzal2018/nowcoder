#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int N;
    cin >> N;
    int money[] = { 1,5,10,20,50,100 };
    vector<vector<long long>> dp(N + 1, vector<long long>(6, 0));
    dp[0][0] = 1;
    for (int i = 1; i<6; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i<N + 1; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i<N + 1; i++) {
        for (int j = 1; j<6; j++) {
            dp[i][j] = dp[i][j - 1] + ((i >= money[j]) ? (dp[i - money[j]][j]) : 0);
        }
    }
    cout << dp[N][5] << endl;
    return 0;
}
添加笔记
