#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};

Point points[500001];

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    //按照y升序 x降序排列
    sort(points, points + n,
         [](Point & p1, Point & p2)
    {
        return p1.y == p2.y ? p1.x > p2.x : p1.y < p2.y;
    });
    printf("%d %d\n", points[n - 1].x, points[n - 1].y);
    int maxx = points[n - 1].x;
    for (int i = n - 2; i >= 0; i--)
    {
        if (points[i].x > maxx)
        {
            printf("%d %d\n", points[i].x, points[i].y);
			maxx = points[i].x;
        }
    }
    return 0;
}