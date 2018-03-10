#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int r2;
    cin >> r2;
    int cnt = 0;
    int r = sqrt(r2);
    if (r*r == r2)
    {
        cnt += 4;
    }
    for (int x = 1; x < sqrt(r2); x++)
    {
        int y = sqrt(r2 - x*x);
        //只要算第一象限
        if (x*x + y*y == r2) {
            cnt += 4;
        }
    }
    cout << cnt << endl;
    return 0;
}