#include <iostream>
#include <vector>
#include <algorithm>
  
using namespace std;
  
int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i<n; i++) {
        cin >> data[i];
    }
    long long maxval = 0;
    for (int i = 0; i < n; i++)
    {
        long long sum = data[i];
        for (int j = i-1; j >= 0; j--)
        {
            if (data[j] < data[i]) {
                break;
            }
            sum+=data[j];
        }
        for (int j = i+1; j < n; j++)
        {
            if (data[j] < data[i]) {
                break;
            }
            sum+=data[j];
        }
        maxval = max(maxval, sum*data[i]);
    }
    cout << maxval << endl;
    return 0;
}