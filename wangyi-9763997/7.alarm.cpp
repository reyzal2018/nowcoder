#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> alarm;
    while (N--)
    {
        int Hi, Mi;
        cin >> Hi >> Mi;
        alarm.push_back(Hi * 60 + Mi);
    }
    int X;
    cin >> X;
    int hi,mi, ClassTime;
    cin >> hi>>mi;
    ClassTime = hi * 60 + mi - X;
    sort(alarm.begin(), alarm.end(), greater<int>());
    auto it = lower_bound(alarm.begin(), alarm.end(), ClassTime, greater<int>());
    cout << *it / 60 << " " << *it % 60 << endl;
    return 0;
}