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

double sqr(double x) 
{
	return x * x;
}

struct pt
{
	double x, y;
	pt(){}
	pt(double x, double y) : x(x), y(y) {}

	void read ()
	{
		cin >> x >> y;
	}

	double dist (pt o)
	{
		return sqr(x - o.x) + sqr(y - o.y);
	}
} d[10];

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 4; i ++) d[i].read();

	double A = d[2].y - d[1].y;
	double B = d[1].x - d[2].x;
	double C = - A * d[1].x - B * d[1].y;

	double first = A * d[3].x + B * d[3].y + C;
	double second = A * d[4].x + B * d[4].y + C;

	if (fabs(first) < eps && fabs(second) < eps)
	{
		if ((d[3].x < max(d[2].x, d[1].x) + eps && d[3].x + eps > min(d[2].x, d[1].x) 
			&& d[3].y < max(d[2].y, d[1].y) + eps && d[3].y + eps > min(d[2].y, d[1].y))
			|| (d[4].x < max(d[2].x, d[1].x) + eps && d[4].x + eps > min(d[2].x, d[1].x) 
			&& d[4].y < max(d[2].y, d[1].y) + eps && d[4].y + eps > min(d[2].y, d[1].y)))
		{
			cout << "YES";
		}
		else if ((d[1].x < max(d[3].x, d[4].x) + eps && d[1].x + eps > min(d[3].x, d[4].x) 
			&& d[1].y < max(d[3].y, d[4].y) + eps && d[1].y + eps > min(d[3].y, d[4].y))
			|| (d[2].x < max(d[3].x, d[4].x) + eps && d[2].x + eps > min(d[3].x, d[4].x) 
			&& d[2].y < max(d[3].y, d[4].y) + eps && d[2].y + eps > min(d[3].y, d[4].y)))
		{
			cout << "YES";
		}
		else cout << "NO";
		return 0;
	}

	double A2 = d[3].y - d[4].y;
	double B2 = d[4].x - d[3].x;
	double C2 = - A2 * d[3].x - B2 * d[3].y;

	double first2 = A2 * d[1].x + B2 * d[1].y + C2;
	double second2 = A2 * d[2].x + B2 * d[2].y + C2;

	if (((first + eps > 0 && second < eps) || (first < eps && second + eps > 0)) &&
		((first2 + eps > 0 && second2 < eps) || (first2 < eps && second2 + eps > 0))) 
		cout << "YES";
	else cout << "NO";
}


