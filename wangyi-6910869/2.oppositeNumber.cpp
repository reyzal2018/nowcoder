#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    stringstream ss;
    ss << n;
    string s1 = ss.str();
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    bool step = 0;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        int sum = (s1[i] - '0') + (s2[i] - '0') + step;
        if (sum >= 10) {
            step = 1;
            sum %= 10;
        }
        else {
            step = 0;
        }
        s1[i] = '0' + sum;
    }
    if (step)
    {
        s1 = "1" + s1;
    }
    auto it = s1.begin();
    while (it != s1.end())
    {
        if (*it == '0') {
            it = s1.erase(it);
        }
        else {
            break;
        }
    }
    cout << s1 << endl;
    return 0;
}
