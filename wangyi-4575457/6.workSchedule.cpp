#include <bits/stdc++.h>
 
using namespace std;
 
vector<string> works;
 
int result = 0;
 
void dfs(int scheme[6],int index)
{
    if (index == works.size())
    {
        result++;
        return;
    }
    if (works[index].size() == 0) {
        dfs(scheme, index + 1);
        return;
    }
    for (int i = 0; i < works[index].size(); i++)
    {
        if (scheme[works[index][i] - '0']) continue;
        scheme[works[index][i] - '0'] = 1;
        dfs(scheme, index + 1);
        scheme[works[index][i] - '0'] = 0;
    }
}
//这里题目描述不清晰，其实只要每个人做一个事情就行了，没必要所有事情都做完，回溯即可
int main()
{
    int n;
    cin >> n;
    works.resize(n);
    for (int i = 0; i < n; i++)
        cin >> works[i];
    int scheme[6] = {0};
    dfs(scheme, 0);
    cout << result << endl;
    return 0;
}