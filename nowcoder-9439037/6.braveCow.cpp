#include<bits/stdc++.h>
 
using namespace std;
int result = 0;
int n, K;
int best[32] = { 0 };
 
void dfs(int cur,int flag,int sum) {
    if (cur == K)
    {
        result = max(result,sum);
        return;
    }
    for (int i = 0; i < 32; i++)
    {
        if (i & flag)
            continue;
        dfs(cur + 1, i | flag, sum + best[i]);
    }
}
int main()
{
    cin >> n >> K;
    vector<vector<int>> data(n, vector<int>(5));
    int maxv[5] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> data[i][0] >> data[i][1] >> data[i][2] >> data[i][3] >> data[i][4];
        for (int k = 0; k < 5; k++)
        {
            maxv[k] = max(maxv[k], data[i][k]);
        }
        //这里是计算当使用当前装备第12345个属性时，加成是多少
        //best记录最大加成
        //11111 表示使用装备5个属性
        //11110 使用装备第1234属性 11101 使用装备第1235属性 类推
        for (int j = 1; j < 32; j++)
        {
            int temp = 0;
            for (int k = 0; k < 5; k++)
            {
                if (j&(1 << k)) {
                    temp += data[i][k];
                }
            }
            best[j] = max(best[j], temp);
        }
    }
    if (K >= 5)
    {
        //大于5肯定单属性最高的
        for (int i = 0; i < 5; i++)
        {
            result += maxv[i];
        }
    }
    else {
        //小于5
        //选单件5个属性的
        //选单件4个属性的，下一件是1个属性
        //选单件3个属性的，下一件可以2个属性或者1个属性
        //...可以动态规划，小规模直接dfs就行了
        dfs(0, 0,0);
    }
    cout << result << endl;
    return 0;
}