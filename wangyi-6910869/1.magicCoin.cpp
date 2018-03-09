#include <iostream>
#include <string>
 
using namespace std;
 
void getPath(string& s,int n) {
    if (n == 0) return;
    if ((n - 1) & 1)
    {
        n = (n - 2) / 2;
        getPath(s, n);
        s.push_back('2');
    }
    else {
        n = (n - 1) / 2;
        getPath(s, n);
        s.push_back('1');
    }
}
 
int main()
{
    int n;
    cin >> n;
    string s;
    getPath(s, n);
    cout << s << endl;
    return 0;
}