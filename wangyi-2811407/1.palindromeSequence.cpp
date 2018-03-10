#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,k;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    int l = 0;
    int r = n - 1;
    int t = 0;
    while (l < r)
    {
        if (data.size() == 1) break;
        if (data[l] == data[r])
        {
            l++;
            r--;
            continue;
        }
        if (data[l] < data[r]) {
            data[l] += data[l + 1];
            data.erase(data.begin() + l + 1);
            t++;
            r--;
        }
        else {
            data[r] += data[r - 1];
            data.erase(data.begin() + r - 1);
            t++;
            r--;
        }
    }
    cout << t << endl;
    return 0;
}