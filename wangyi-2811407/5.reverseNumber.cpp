#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
 
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    stringstream xss, yss;
    xss << x;
    yss << y;
    string xs = xss.str();
    reverse(xs.begin(), xs.end());
    string ys = yss.str();
    reverse(ys.begin(), ys.end());
    while (xs.length() < ys.length()) {
        xs = "0" + xs;
    }
    while (xs.length() > ys.length()) {
        ys = "0" + ys;
    }
    int step = 0;
    for (int i = xs.length() - 1; i >= 0; i--) {
        int sum = ys[i] - '0' + xs[i] - '0' + step;
        if (sum >= 10) {
            sum %= 10;
            step = 1;
        }
        else {
            step = 0;
        }
        xs[i] = sum + '0';
    }
    if (step == 1)
        xs = "1" + xs;
    reverse(xs.begin(), xs.end());
    auto it = xs.begin();
    while (it != xs.end()) {
        if (*it == '0')
            it = xs.erase(it);
        else
            break;
    }
    cout << xs << endl;
    return 0;
}