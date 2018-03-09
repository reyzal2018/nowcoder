#include <iostream>
#include <string>
#include <cmath>
 
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int kind = 0;
    int sumlen = 0;
    int len = 0;
    char ch = s.front();
    for (auto& it : s) {
        if (ch == it) {
            len ++;
        }
        else {
            ch = it;
            sumlen += len;
            len = 1;
            kind ++;
        }
    }
    sumlen += len;
    kind++;
    printf("%.2lf", round(sumlen / (double)kind * 100) / 100.0);
    return 0;
}