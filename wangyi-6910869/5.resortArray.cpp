#include <iostream>
#include <functional>
#include <algorithm>
#include <list>
#include <vector>
 
using namespace std;
 
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int t4 = 0, t0 = 0;
        int tmp;
        while (n-- )
        {
            cin >> tmp;
            if (tmp % 4 == 0)
            {
                t4++;
            }
            else if (tmp % 2 != 0) {
                t0++;
            }
        }
        if (t0 <= t4)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}