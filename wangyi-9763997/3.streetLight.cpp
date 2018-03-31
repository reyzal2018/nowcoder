#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    while (n--) {
        int l;
        cin >> l;
        int count = 0;
        while (l > 0)
        {
            char c;
            cin >> c;
            l--;
            if (c == '.') {
                //每一个灯 照亮三个点
                count++;
                if(l-- > 0)
                    cin >> c;
                if (l-- > 0)
                    cin >> c;
            }
        }
        cout << count << endl;
    }
    return 0;
}