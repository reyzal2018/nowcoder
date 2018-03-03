//编程题1 用户喜好
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> user(n);
	map<int, vector<int>> dp;
	for (size_t i = 0; i < n; i++)
    {
        cin >> user[i];
		dp[user[i]].push_back(i);
	}
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        if (dp.count(k) == 0)
            cout << 0 << endl;
        else
        {
            //第一个大于等于l出现的位置
            auto l1 = std::lower_bound(dp[k].begin(), dp[k].end(), l);
            if (l1 == dp[k].end() || *l1 > r)
            {
                cout << 0 << endl;
                continue;
            }
            //第一个大于等于r出现的位置
            auto l2 = std::lower_bound(dp[k].begin(), dp[k].end(), r);
            if (l2 == dp[k].end())
            {
                cout << dp[k].size() - (l1 - dp[k].begin()) << endl;
                continue;
            }
            cout << (l2 - dp[k].begin()) - (l1 - dp[k].begin()) + ((*l2 == r) ? 1 : 0) << endl;
        }
    }
    return 0;
}
