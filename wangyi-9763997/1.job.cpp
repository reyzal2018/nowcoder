#include <bits/stdc++.h>
 
using namespace std;
 
 
//代码写的有点绕，基本思想就是将工作和能力都排序，然后都从小开始遍历
//复杂度max(NlogN,MlogM,N+M)
int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> job(N);
    for (int i = 0; i < N; i++)
    {
        cin >> job[i].first >> job[i].second;
    }
    vector<pair<int,int>> friends(M);
    vector<int> earn(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> friends[i].first;
        friends[i].second = i;
    }
    sort(friends.begin(), friends.end(), [&](pair<int, int> &e1, pair<int, int>& e2) {return e1.first < e2.first; });
    sort(job.begin(), job.end(), [&](pair<int, int> &e1, pair<int, int>& e2) {return e1.first < e2.first; });
 
    int indexFriend = 0;
    int indexJob = 0;
    int preEarn = 0;
    while (indexFriend < M && indexJob < N)
    {
        if (friends[indexFriend].first < job[indexJob].first)
            indexFriend++;
        else if (indexJob == N-1 || friends[indexFriend].first < job[indexJob + 1].first) {
            preEarn = earn[friends[indexFriend].second] = max(preEarn, job[indexJob].second);
            indexFriend++;
        }
        else {
            preEarn = max(preEarn, job[indexJob].second);
            indexJob++;
        }
    }
    for (int i = 0; i < M; i++)
    {
        cout << earn[i] << endl;
    }
    return 0;
}