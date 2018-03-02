//附加题
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int GetPerfectValue(vector<int>& value)
{
    return value[0] * value[1] * value[2] * value[3] +
           value[4] * value[5] * value[10] * value[11] +
           value[6] * value[7] * value[12] * value[13] +
           value[8] * value[9] * value[14] * value[15] +
           value[16] * value[17] * value[18] * value[19] +
           value[20] * value[21] * value[22] * value[23]
           ;
}
//每一个面顺时针转动时置换矩阵 -1表示不变
int mat[][24] =
{
    { 1, 3, 0, 2, 23, 22, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 9, 8 },
    { 10, 4, -1, -1, 18, -1, -1, -1, -1, 0, 19, -1, -1, -1, -1, 1, -1, -1, 15, 9, 21, 23, 20, 22 },
    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 21, 20, 10, 11, 12, 13, 18, 16, 19, 17, 15, 14, -1, -1 },
    { 20, -1, 22, -1, 10, 4, 0, -1, -1, -1, 11, 5, 2, -1, -1, -1, 6, -1, 12, -1, 16, -1, 18, -1 },
    { -1, 21, -1, 23, -1, -1, -1, 1, 9, 15, -1, -1, -1, 3, 8, 14, -1, 7, -1, 13, -1, 17, -1, 19 },
    { -1, -1, 11, 5, -1, 16, 12, 6, 2, -1, -1, 17, 13, 7, 3, -1, 14, 8, -1, -1, -1, -1, -1, -1 }
};
 
 
void rotate(vector<int>& value, int side)
{
    vector<int> newValue = value;
    for (size_t i = 0; i < 24; i++)
    {
        if (mat[side][i] != -1)
            newValue[i] = value[mat[side][i]];
    }
    value = newValue;
}
 
void dfs(vector<int>& value, int depth, int& maxValue)
{
    maxValue = max(maxValue, GetPerfectValue(value));
    if (depth == 5)
    {
        return;
    }
    vector<int> tmp = value;
    for (size_t i = 0; i < 6; i++)
    {
        rotate(value, i);
        dfs(value, depth + 1, maxValue);
        rotate(value, i);
        rotate(value, i);
        dfs(value, depth + 1, maxValue);
        value = tmp;
    }
}
int main()
{
    vector<int> value(24, 0);
    for (size_t i = 0; i < 24; i++)
    {
        cin >> value[i];
    }
    int maxValue = GetPerfectValue(value);
    dfs(value, 0, maxValue);
    cout << maxValue << endl;
    return 0;
}