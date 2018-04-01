#include <bits/stdc++.h>
using namespace std;
 
long long n, w;
vector<long long> good;
long long result = 0;
 
void dfs(int cur, long long sum)
{
    if (sum <= w && cur == n)
        result++;
    if (cur == n || sum > w)
        return;
    dfs(cur + 1, sum + good[cur]);
    dfs(cur + 1, sum);
}
int main() {
    cin >> n >> w;
    good.resize(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> good[i];
        sum += good[i];
    }
    if (sum <= w) {
        //全部都可以放入
        result = pow(2, n);
    }
    else {
        dfs(0, 0);
    }
    cout << result << endl;
    return 0;
}