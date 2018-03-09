#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    while(cin >> N){
        vector<int> data(N);
        for (int i = 0; i<N; i++) {
            cin >> data[i];
        }
        sort(data.begin(), data.end());
        int nmin = data[0];
        int nmax = data[N - 1];
        if (nmin == nmax) {
            cout << N*(N - 1) / 2 << " " << N*(N - 1) / 2 << endl;
        }
        else {
            //差最大的数 mincount*maxcount
            int mincount = 0, maxcount = 0;
            int sub = 0x7fffffff;
            int resmin = 0;
            int sameCount = 1;
            for (int i = 0; i<N; i++) {
                if (i > 0)
                {
                    sub = min(sub, data[i] - data[i - 1]);
                    if (data[i] == data[i - 1])
                    {
                        sameCount++;
                    }
                    else {
                        if (sameCount > 1) {
                            resmin += sameCount*(sameCount - 1)/2;
                        }
                        sameCount = 1;
                    }
                }
                if (data[i] == nmin)
                    mincount++;
                if (data[i] == nmax)
                    maxcount++;
            }
            if (sameCount > 1) {
                resmin += sameCount*(sameCount - 1)/2;
            }            
            if (resmin == 0) {
                for (int i = 1; i < N; i++) {
                    if (data[i] - data[i - 1] == sub) {
                        resmin++;
                    }
                }
            }
            cout << resmin << " " << mincount*maxcount << endl;
        }        
    }
    return 0;
}
