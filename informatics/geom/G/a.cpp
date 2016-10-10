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
const double pi = acos(-1.0);

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);                              

	double x, y, ans;
	cin >> x >> y;
	if (x == 0 && y == 0)
	{
		cout << 0;
		return 0;
	}
	/*if (x >= 0 && y >= 0) ans = 0;re
	else if (x <= 0 && y >= 0) ans = pi / 2.0;
	else if (x <= 0 && y <= 0) ans = pi;
	else ans = 3.0 * pi / 2.0;
	x = fabs(x);
	y = fabs(y);*/
	ans = atan2(y, x);
	if(ans < 0) ans += 2 * pi;
	printf("%.12f", ans);
}


