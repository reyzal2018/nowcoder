#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{  
    int N, D;
    cin >> N >> D;
    vector<vector<int>> data(N, vector<int>(N, 0));
    D--;
    int maxResult = 0;
    //横
    for (int i = 0; i < N; i++)
    {
        int rowResult = 0;
        for (int j = 0; j < N; j++)
        {
            cin >> data[i][j];
            rowResult += data[i][j];
            if (j >= D) {
                maxResult = max(maxResult, rowResult);
                rowResult -= data[i][j - D];
            }
        }
    }
    //列
    for (int i = 0; i < N; i++)
    {
        int colResult = 0;
        for (int j = 0; j < N; j++)
        {
            colResult += data[j][i];
            if (j >= D) {
                maxResult = max(maxResult, colResult);
                colResult -= data[j - D][i];
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int lrResult = 0;
            int i1 = i, j1 = j;
            //左到右
            while (i1 < N&&j1 < N)
            {
                lrResult += data[i1][j1];
                if (i1-i >= D)
                {
                    maxResult = max(maxResult, lrResult);
                    lrResult -= data[i1 - D][j1 - D];
                }
                i1++;
                j1++;
            }
            int rlResult = 0;
            i1 = i;
            j1 = j;
            //左到右
            while (i1 < N&&j1 >= 0)
            {
                rlResult += data[i1][j1];
                if (i1 - i >= D)
                {
                    maxResult = max(maxResult, rlResult);
                    rlResult -= data[i1 - D][D + j1];
                }
                i1++;
                j1--;
            }
        }
    }
    cout << maxResult << endl;
    return 0;
}