#include <bits/stdc++.h>
 
using namespace std;
 
 
int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    vector<int> dataIndex(1001, 100);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
        dataIndex[data[i]] = i;
    }
    sort(dataIndex.begin(), dataIndex.end());
    auto it = dataIndex.begin();
    while(it != dataIndex.end())
    {
        if (*it == 100) break;
        if(it != dataIndex.begin())
            cout << " ";
        cout << data[*it];
        it++;
    }
    cout << endl;
    return 0;
}