#include<bits/stdc++.h>
 
using namespace std;
int n, s;
vector<int> p;
 
int result;
 
void dfs(int cur,int minv,int sum,int count)
{
    if (sum >= s && sum - minv < s) {
        result = max(result, count);
    }
    if (sum > s || cur == n)
        return;
    dfs(cur + 1, min(minv, p[cur]), sum + p[cur], count + 1);
    dfs(cur + 1, minv, sum, count);
}
int main()
{
    cin >> n >> s;
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    result = -1;
    dfs(0, 0x3d3d3d3d, 0, 0);
    cout << result << endl;
    return 0;
}