// Gino Liza

#include <bits/stdc++.h>

using namespace std;

#define eps 1e-6

struct Pt
{
    double x, y;
    Pt(double a = 0, double b = 0) : x(a), y(b) {}
    Pt operator-(const Pt &a) const
    {
        return Pt(x - a.x, y - a.y);
    }
    Pt operator+(const Pt &a) const
    {
        return Pt(x + a.x, y + a.y);
    }
    Pt operator*(const double a) const
    {
        return Pt(x * a, y * a);
    }
    bool operator<(const Pt &a) const
    {
        if (fabs(x - a.x) > eps)
            return x < a.x;
        if (fabs(y - a.y) > eps)
            return y < a.y;
        return false;
    }
    bool operator==(const Pt &a) const
    {
        return fabs(x - a.x) < eps && fabs(y - a.y) < eps;
    }
};
double dist(Pt a, Pt b)
{
    return hypot(a.x - b.x, a.y - b.y);
}
double punto(Pt a, Pt b)
{
    return a.x * b.x + a.y * b.y;
}
double cruz(Pt o, Pt a, Pt b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
double cruz2(Pt a, Pt b)
{
    return a.x * b.y - a.y * b.x;
}
int entre(Pt a, Pt b, Pt c)
{
    return punto(c - a, b - a) >= -eps && punto(c - b, a - b) >= -eps;
}
int seg(Pt a, Pt b, Pt c)
{
    return entre(a, b, c) && fabs(cruz(a, b, c)) < eps;
}
double segDist(Pt a, Pt b, Pt o)
{
    return fabs(cruz(a, b, o)) / dist(a, b);
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        Pt o, A[32];
        int x, y;
        scanf("%d %d", &x, &y);
        o = Pt(x, y);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            A[i] = Pt(x, y);
        }
        double ret = dist(o, A[0]);
        for (int i = 1; i < n; i++)
            ret = min(ret, dist(o, A[i]));
        for (int i = 0, j = n - 1; i < n; j = i++)
        {
            if (!entre(A[i], A[j], o))
                continue;
            double t = segDist(A[i], A[j], o);
            ret = min(ret, t);
        }
        printf("%.3lf\n", ret);
    }
    return 0;
}
