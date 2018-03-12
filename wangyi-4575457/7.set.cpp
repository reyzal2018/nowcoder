#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    set<double> s;
    for (int p = w; p <= x; p++)
    {
        for (int q = y; q <= z; q++)
        {
            s.insert(1.0*p / q);
        }
    }
    cout << s.size() << endl;
    return 0;
}