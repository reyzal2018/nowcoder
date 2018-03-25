#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int result = 0;
    int i = 0;
    while(i < n)
    {
        int num;
        cin >> num;
        //如果当前数等于i 则次数+1
        //如果下面一个数等于i+1 则次数也是+1
        if (num == i+1) {
            if (i < n) {
                i++;
                cin >> num;
            }
            result++;
        }
        i++;
    }
    cout << result << endl;
    return 0;
}
