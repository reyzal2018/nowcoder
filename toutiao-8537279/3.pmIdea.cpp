#include <bits/stdc++.h>
 
using namespace std;
 
struct Task
{
    int id;
    int pm;
    int time;
    int pri;
    int dur;
};
 
vector<vector<Task>> pmtasks;
map<int, int> result;
int proid = 1;
struct Programer
{
    Programer()
    {
        t = 0;
        this->id = proid++;
    }
    int t;//当前的时间
    int id;
    int doTask()
    {
        vector<Task>::iterator findT;
        int index = -1;
        for (size_t i = 0; i < pmtasks.size(); i++)
        {
            auto& tasks = pmtasks.at(i);
            if (tasks.size() == 0) continue;
            auto it = tasks.begin();
            while (it!= tasks.end() && it->time > t)
                it++;
            if (it == tasks.end()) continue;
            if (index == -1)
            {
                findT = it;
                index = i;
            }
            else
            {
                if (it->dur < findT->dur)
                {
                    findT = it;
                    index = i;
                }
            }
        }
        if (index != -1)
        {
            t += findT->dur;
            result[findT->id] = t;
            pmtasks.at(index).erase(findT);
            return 1;
        }
        else
            t++;
        return 0;
    }
};
 
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    pmtasks.resize(n);
    for (size_t i = 0; i < p; i++)
    {
        Task task;
        cin >> task.pm >> task.time >> task.pri >> task.dur;
        task.id = i;
        pmtasks.at(task.pm - 1).push_back(task);
    }
    for (size_t i = 0; i < pmtasks.size(); i++)
    {
        auto& tasks = pmtasks.at(i);
        if (tasks.size() == 0) continue;
        sort(tasks.begin(), tasks.end(), [](Task & t1, Task & t2)
        {
            if (t1.pri == t2.pri)
            {
                if (t1.dur == t2.dur)
                {
                    return t1.time < t2.time;
                }
                else return t1.dur < t2.dur;
            }
            else return t1.pri > t2.pri;
        });
    }
    vector<Programer> pros(m);
    while (p > 0)
    {
        sort(pros.begin(), pros.end(), [&](Programer & t1, Programer & t2)
        {
            return t1.t < t2.t;
        });
        p -= pros.begin()->doTask();
    }
    for (auto &it : result)
        cout << it.second << endl;
    return 0;
}