#include <iostream>
#include <vector>
 
using namespace std;
int main()
{
    int n;
    cin>> n;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    int sum = 0;
    for(int i = 2;i<=n;i++){
        sum += dp[i-2];
        dp[i] = 2*sum;
    }
    cout <<dp[n]<<endl;
    return 0;
}