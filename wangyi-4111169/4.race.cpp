#include <bits/stdc++.h>
 
using namespace std;
int main()
{  
    double result = 0;
    int n;
    cin >> n;
    while (n--)
    {
        result += 1.0 / (n + 1);
    }
    printf("%.4lf", result);
    return 0;
}