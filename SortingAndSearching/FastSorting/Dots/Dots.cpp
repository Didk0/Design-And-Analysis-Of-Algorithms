// II начин:
//struct Point
//{
//    bool start = false, end = false, dot = false;
//    int coord = INT_MAX, intervals = 0, originalPos = INT_MAX;
//};
//
//int n, m;
//Point points[100005];
//
//int main()
//{
//    cin >> n >> m;
//    int size = 0;
//    for (int i = 0; i < n; i++)
//    {
//        int s, e;
//        cin >> s >> e;
//        if (s > e) swap(s, e);
//
//        points[size].start = true;
//        points[size++].coord = s;
//        points[size].end = true;
//        points[size++].coord = e;
//    }
//
//    for (int i = 0; i < m; i++)
//    {
//        int d;
//        cin >> d;
//
//        points[size].dot = true;
//        points[size].originalPos = i;
//        points[size++].coord = d;
//    }
//
//    std::sort(points, points + size, [](const Point& p1, const Point& p2)->bool {
//        if (p1.coord < p2.coord)
//            return true;
//        else if (p1.coord == p2.coord)
//        {
//            if (p1.start && (p2.dot || p2.end))
//                return true;
//            else if (p1.dot && p2.end)
//                return true;
//        }
//        return false;
//        });
//
//    int intervals = 0;
//    for (int i = 0; i < size; i++)
//    {
//        if (points[i].start)
//            intervals++;
//        if (points[i].dot)
//            points[i].intervals = intervals;
//        if (points[i].end)
//            intervals--;
//    }
//
//    sort(points, points + size, [](const Point& p1, const Point& p2)->bool {
//        return p1.originalPos < p2.originalPos;
//        });
//
//    for (int i = 0; i < size; i++)
//    {
//        if (points[i].originalPos < m)
//            cout << points[i].intervals << ' ';
//    }
//
//    return 0;
//}

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define start 0
#define dot 1
#define end 2 

struct Point
{
    int coordinate;
    int type;
    int index = INT_MAX;

    bool operator <(Point other)
    {
        return coordinate < other.coordinate ||
            (coordinate == other.coordinate && type < other.type);
    }

};

bool cmpByIndex(Point a, Point b)
{
    return a.index < b.index;
}

int n, m;
Point points[300100];

int main()
{
    cin >> n >> m;
    int tmpStart, tmpEnd;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmpStart >> tmpEnd;

        if (tmpEnd < tmpStart)
            swap(tmpStart, tmpEnd);

        points[i].coordinate = tmpStart;
        points[i].type = start;
        points[n + i].coordinate = tmpEnd;
        points[n + i].type = end;
    }

    n *= 2;

    int tmpDot;
    for (int i = 0; i < m; ++i)
    {
        cin >> tmpDot;

        points[n + i].coordinate = tmpDot;
        points[n + i].type = dot;
        points[n + i].index = i;
    }

    n += m;

    std::sort(points, points + n);

    int intervals = 0;
    for (int i = 0; i < n; ++i)
    {
        switch (points[i].type)
        {
        case start:
            ++intervals;
            break;
        case dot:
            points[i].coordinate = intervals;
            break;
        case end:
            --intervals;
            break;
        }
    }

    std::sort(points, points + n, cmpByIndex);

    for (int i = 0; i < m; ++i)
    {
        cout << points[i].coordinate << ' ';
    }

    return 0;
}