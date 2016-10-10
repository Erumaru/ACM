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

struct pt
{
	double x, y;
	pt(){}
	pt(double x, double y) : x(x), y(y) {}
	void read ()
	{
		cin >> x >> y;
	}

} d[5];

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 1; i <= 3; i ++) d[i].read();

	double A = d[2].y - d[3].y;
	double B = d[3].x - d[2].x;
	double C = - A * d[2].x - B * d[2].y;

	double dot = A * d[1].x + B * d[1].y + C;
	if (fabs(dot) > eps) 
	{
		cout << "NO";
		return 0;
	}

	if (d[1].x + eps > min(d[2].x, d[3].x) && d[1].x < max(d[2].x, d[3].x) + eps
		&& d[1].y + eps > min(d[2].y, d[3].y) && d[1].y < max(d[2].y, d[3].y) + eps) cout << "YES";
	else cout << "NO";	
}


