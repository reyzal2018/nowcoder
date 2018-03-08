#include <iostream>
using namespace std;
 
int main()
{
    int status[] = { 0,1,0, 1, 1, 0, 1, 0, 1, 1 };
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (status[n % 10] == 1 ? "niu" : "yang") << endl;
    }
    return 0;
}