#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> taixx(n);
    vector<int> taixy(n);
    int gx, gy;
    int wt, tt;
    for (int i = 0; i < n; i++)
        cin >> taixx[i];
    for (int i = 0; i < n; i++)
        cin >> taixy[i];
    cin >> gx >> gy;
    cin >> wt >> tt;
    //走路需要的时间
    int result = abs(gx*wt) + abs(gy*wt);
    //走到打车点再打车的时间
    for (int i = 0; i < n; i++)
    {
        int walktime = abs(taixx[i] * wt) + abs(taixy[i] * wt);
        result = min(walktime + (abs(gx - taixx[i]) + abs(gy - taixy[i]))*tt, result);
    }
    cout << result << endl;
    return 0;
}