#include <bits/stdc++.h>
 
using namespace std;
 
bool visited[8][8][8][8];
int N, M;
 
vector<string> mmap;
 
struct Pos
{
    int stage;
    int manx, many;
    int boxx, boxy;
    bool checkman()
    {
        if (manx < 0 || manx >= N || many < 0 || many >= M || mmap[manx][many] != '.')
        {
            return false;
        }
        return true;
    }
    bool checkbox()
    {
        if (boxx < 0 || boxx >= N || boxy < 0 || boxy >= M || mmap[boxx][boxy] != '.')
        {
            return false;
        }
        return true;
    }
    bool checkvisited()
    {
        if (visited[boxx][boxy][manx][many])
        {
            return true;
        }
        visited[boxx][boxy][manx][many] = true;
        return false;
    }
};
 
int main()
{  
    cin >> N >> M;
    int startx, starty;
    int boxx, boxy;
    int finishx, finishy;
    memset(visited, false, 8 * 8 * 8 * 8);
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'X')
            {
                startx = i;
                starty = j;
                s[j] = '.';
            }
            else if (s[j] == '*')
            {
                boxx = i;
                boxy = j;
                s[j] = '.';
            }
            else if (s[j] == '@')
            {
                finishx = i;
                finishy = j;
                s[j] = '.';
            }
        }
        mmap.push_back(s);
    }
    Pos startPos;
    startPos.boxx = boxx;
    startPos.boxy = boxy;
    startPos.manx = startx;
    startPos.many = starty;
    startPos.stage = 0;
    queue<Pos> q;
    q.push(startPos);
    int result = -1;
    while (result == -1 && !q.empty())
    {
        Pos curPos = q.front();
        q.pop();
        static int dir[][2] = {
            { -1,0 },
            { 1,0 },
            { 0,1 },
            { 0,-1 }
        };
        for (int i = 0; i < 4; i++)
        {
            Pos newPos = curPos;
            newPos.stage++;
            newPos.manx += dir[i][0];
            newPos.many += dir[i][1];
            if (!newPos.checkman())
            {
                continue;
            }
            if (newPos.manx == newPos.boxx && newPos.many == newPos.boxy)
            {
                newPos.boxx += dir[i][0];
                newPos.boxy += dir[i][1];
            }
            if (!newPos.checkbox())
            {
                continue;
            }
            if (newPos.checkvisited())
            {
                continue;
            }
            if (curPos.boxx == finishx && curPos.boxy == finishy)
            {
                result = curPos.stage;
                break;
            }
            q.push(newPos);
        }
    }
    cout << result << endl;
    return 0;
}