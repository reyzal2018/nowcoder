#include <iostream>
#include <functional>
#include <algorithm>
#include <list>
#include <vector>
 
using namespace std;
vector<list<int>> vecListPath;
 
void dfs(int i, vector<int>& len,int depth)
{
    if (vecListPath[i].size() == 0)
    {
        len.push_back(depth);
        return;
    }
    for (auto& it : vecListPath[i]) {
        dfs(it, len, depth + 1);
    }
}
 
 
int main()
{
    int n, L;
    cin >> n >> L;
    vecListPath.resize(n, list<int>());
    for (size_t i = 1; i < n; i++)
    {
        int t;
        cin >> t;
        vecListPath[t].push_back(i);
    }
    //0开始 dfs
    vector<int> lens;
    dfs(0, lens, 0);
    sort(lens.begin(), lens.end(),greater<int>());
    if (L <= lens[0])
    {
        cout << L + 1 << endl;
    }
    else {
        int total = lens[0];
        L -= lens[0];
        int sumlen = 0;
        std::for_each(lens.begin(), lens.end(), [&](int x) { sumlen += x; });
        sumlen -= lens[0];
        if (L > sumlen * 2)
        {
            cout << lens[0] + sumlen + 1 << endl;
        }
        else {
            cout << lens[0] + L / 2 + 1 << endl;
        }
    }
    return 0;
}