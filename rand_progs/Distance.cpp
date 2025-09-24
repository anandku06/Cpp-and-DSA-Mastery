#include <bits/stdc++.h>
using namespace std;

class Point
{
    int x, y;
    friend int distance(Point , Point);
    public:
        Point(int a, int b)
        {
            x = a;
            y = b;
        }

        void printCords()
        {
            cout << "Cords are (" << x << ", " << y << ")" << endl;
        }
};


int distance(Point p1, Point p2)
{
    int xdist = p2.x - p1.x;
    int ydist = p2.y - p1.y;

    xdist = pow(xdist, 2);
    ydist = pow(ydist, 2);

    int totalDist = sqrt(xdist + ydist);

    return totalDist;
}

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    Point p1(x1, y1);
    p1.printCords();

    cin >> x2 >> y2;
    Point p2(x2, y2);
    p2.printCords();

    cout << distance(p1, p2) << endl;

    return 0;
}
