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
#define st second
#define mp make_pair
#define pb push_back
#define sz(n) int(n.size())
#define all(n) n.begin(), n.end()


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;
const double eps = 1e-9;

inline double sqr(double x)
{
	return x * x;
}

struct pt
{
	double x, y;
	pt() {}
	pt(double x, double y) : x(x), y(y)	{}

	void read()
	{
		cin >> x >> y;
	}

	double norm()
	{
		return sqrt(sqr(x) + sqr(y));
	}

	pt const operator * (double k)
	{
		return pt(x * k, y * k);
	}

	double const operator * (pt o)
	{
		return x * o.x + y * o.y;
	}

	pt const operator - (pt o)
	{
		return pt(x - o.x, y - o.y);
	}
} A, B, O, P;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);  
	A.read();
	O.read();
	B.read();
	P.read();

	B = B - O;
	A = A - O;
	P = P - O; 
	double first = acos((A * B) / A.norm() / B.norm());
	double second = acos((A * P) / A.norm() / P.norm());
	double third = acos((B * P) / B.norm() / P.norm());
	if (fabs(first - second - third) < eps) cout << "YES";
	else cout << "NO";
}


