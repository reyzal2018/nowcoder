//编程题1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    long long n, k, d1, d2;
    long long maxd, maxb, sum;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> d1 >> d2;
        //得分情况分4种 注意得分是否合法
        //maxb 第二个队伍可能的得分
        //sum 三个队分数相等时需要的场次
        //剩余的场次应该是3的倍数
        //1 b+d1 b b+d2
        maxd = max(d1, d2);
        maxb = (k - d1 - d2);
        sum = (maxd - d1) + maxd + (maxd - d2);
        if (maxb >= 0 &&
                maxb % 3 == 0 &&
                (n - k - sum) >= 0 &&
                (n - k - sum) % 3 == 0)
        {
            cout << "yes" << endl;
            continue;
        }
        //2 b+d1 b b-d2
        maxb = (k - d1 + d2);
        sum = 0 + d1 + (d1 + d2);
        if (maxb >= 0 &&
                maxb % 3 == 0 &&
                maxb / 3 - d2 >= 0 &&
                (n - k - sum) >= 0 &&
                (n - k - sum) % 3 == 0)
        {
            cout << "yes" << endl;
            continue;
        }
        //3 b-d1 b b+d2
        maxb = (k - d2 + d1);
        sum = (d1 + d2) + d2 + 0;
        if (maxb >= 0 &&
                maxb % 3 == 0 &&
                maxb / 3 - d1 >= 0 &&
                (n - k - sum) >= 0 &&
                (n - k - sum ) % 3 == 0)
        {
            cout << "yes" << endl;
            continue;
        }
        //4 b-d1 b b-d2
        maxb = (k + d2 + d1);
        sum = d1 + d2;
        if (maxb >= 0 &&
                maxb % 3 == 0 &&
                maxb / 3 - d1 >= 0 &&
                maxb / 3 - d2 >= 0 &&
                (n - k - sum) >= 0 &&
                (n - k - sum) % 3 == 0)
        {
            cout << "yes" << endl;
            continue;
        }
        cout << "no" << endl;
    }
    return 0;
}