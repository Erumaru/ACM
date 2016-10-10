#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define ft first
#define sqr(n) (n) * (n)
#define st second
#define mp make_pair
#define pb push_back
#define sz(n) int(n.size())
#define all(n) n.begin(), n.end()
#define double long double

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

struct pt
{
    double x, y;
    pt(){}
    pt(double x, double y) : x(x), y(y) {}
    
    void read()
    {
        cin >> x >> y;
    }

    pt const operator + (pt o)
    {
        return pt(x + o.x, y + o.y);
    }

    pt const operator - (pt o)
    {
        return pt(x - o.x, y - o.y);
    }

    pt const operator * (double k)
    {
        return pt(x * k, y * k);
    }

    double dist (pt o)
    {
        return sqrt(sqr(x - o.x) + sqr(y - o.y));
    }

    void norm()
    {
        double len = sqrt(sqr(x) + sqr(y));
        x /= len;
        y /= len;
    }

    void rotate ()
    {
        swap(x, y);
        x = -x;
    }

    bool equal(pt o)
    {
        return abs(x - o.x) < 1e-9 && abs(y - o.y) < 1e-9;
    }
} A, B, C;

int main ()
{
    //freopen ("in", "r", stdin);
    //freopen ("out", "w", stdout); 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    A.read();
    B.read();
    C.read();
    // C = C - B;
    //C = B + C * 1e12;
    double AB = A.dist(B);
    double AC = A.dist(C);
    double BC = B.dist(C);
    if (sqr(AC) > sqr(AB) + sqr(BC) || sqr(AB) > sqr(AC) + sqr(BC))
    {
        printf("%.20Lf", (double)min(A.dist(B), A.dist(C)));
    }
    else 
    {
        double a = C.y - B.y;
        double b = B.x - C.x;
        double c = - a * B.x - b * B.y;

        printf("%.12Lf", (double)abs(a * A.x + b * A.y + c) / sqrt(a * a + b * b));    
    }
}



