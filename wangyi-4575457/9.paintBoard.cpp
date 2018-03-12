#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> maxCount(n, 0);
    vector<int> lastChar(n);
    vector<int> curCount(n, 1);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (i == 0) {
                lastChar[j] = s[j];
            }
            else {
                if (s[j] == lastChar[j]) {
                    curCount[j]++;
                }
                else {
                    maxCount[j] = max(maxCount[j], curCount[j]);
                    curCount[j] = 1;
                }
                lastChar[j] = s[j];
            }
        }
    }
    int result = 0;
    //处理最后的情况
    for (int i = 0; i < n; i++) {
        maxCount[i] = max(maxCount[i], curCount[i]);
        result = max(result, maxCount[i]);
    }
    cout << result << endl;
    return 0;
}