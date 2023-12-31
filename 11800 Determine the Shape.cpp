// Joel Challco
// Emanuel Galdos
// Gino Liza
// Misael Rodriguez

#include <bits/stdc++.h>

using namespace std;

#define BIGGER(a, b) (a >= b ? a : b)
#define getInt(a) scanf("%d", &a);

struct Point
{
    int x;
    int y;
};

long long int obtDistancia(Point P1, Point P2)
{
    return (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y);
}

bool verfPerp(Point P1, Point P2, Point P3)
{
    return (obtDistancia(P1, P3) == (obtDistancia(P1, P2) + obtDistancia(P2, P3)));
}

bool verfParal(Point P1, Point P2, Point P3, Point P4)
{
    return ((P1.x - P2.x) * (P3.y - P4.y) == (P1.y - P2.y) * (P3.x - P4.x));
}

int verf(Point P1, Point P2, Point P3, Point P4)
{
    long long int len12, len23, len34, len41;

    len12 = obtDistancia(P1, P2);
    len23 = obtDistancia(P2, P3);
    len34 = obtDistancia(P3, P4);
    len41 = obtDistancia(P4, P1);

    bool perp1 = verfPerp(P1, P2, P3);

    if ((P1.x + P3.x == P2.x + P4.x) && (P1.y + P3.y == P2.y + P4.y))
    {
        if (perp1)
        {
            if (len12 == len23 && len23 == len34 && len34 == len41 && len41 == len12)
            {
                return 6;
            }

            else if (len12 == len34 && len23 == len41 && len12 != len41)
            {
                return 5;
            }
        }

        else
        {
            if (len12 == len23 && len23 == len34 && len34 == len41 && len41 == len12)
            {
                return 4;
            }

            else if (len12 == len34 && len23 == len41 && len12 != len41)
            {
                return 3;
            }
        }
    }

    bool parr1 = verfParal(P1, P2, P3, P4);
    bool parr2 = verfParal(P1, P4, P3, P2);

    if (parr1 ^ parr2)
    {
        return 2;
    }

    return 1;
}

int main()
{
    int T, tp = 1;
    Point PP[4];
    int indexArr[4] = {0, 1, 2, 3};
    int i, j, k, l;
    int maxx;

    getInt(T)

    while (T--)
    {
        maxx = 1;

        getInt(PP[0].x)
        getInt(PP[0].y)
        getInt(PP[1].x)
        getInt(PP[1].y)
        getInt(PP[2].x)
        getInt(PP[2].y)
        getInt(PP[3].x)
        getInt(PP[3].y) 
        
        do{
            maxx = BIGGER(maxx, verf(PP[indexArr[0]], PP[indexArr[1]], PP[indexArr[2]], PP[indexArr[3]]));
        }while (next_permutation(indexArr, indexArr + 3));

        switch (maxx)
        {
        case 1:
            printf("Case %d: Ordinary Quadrilateral\n", tp);
            break;
        case 2:
            printf("Case %d: Trapezium\n", tp);
            break;
        case 3:
            printf("Case %d: Parallelogram\n", tp);
            break;
        case 4:
            printf("Case %d: Rhombus\n", tp);
            break;
        case 5:
            printf("Case %d: Rectangle\n", tp);
            break;
        case 6:
            printf("Case %d: Square\n", tp);
            break;
        }

        tp++;
    }

    return 0;
}