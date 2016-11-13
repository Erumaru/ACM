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

#define f first
#define s second
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

struct pt
{
	ll x, y;
	pt(){}
	pt(ll x, ll y) : x(x), y(y) {}

	ll vect (const pt &o)
	{
		return x * o.y - o.x * y;
	}	

	void read()
	{
		scanf("%lld%lld", &x, &y);
	}

	ll trap (const pt &o)
	{
		return (o.x + x) * (y - o.y);
	}

	void print()
	{
		printf("%lld %lld\n", x, y);
	}
} p[100100];

vector <pt> up, down;

bool cmp(pt a, pt b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp2(pt a, pt b)
{
	return a.x > b.x || (a.x == b.x && a.y < b.y);
}


int n;
ll pref[100100], suff[100100];

int main ()
{      	
	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) 
	{
		p[i].read();
	}	

	sort(p + 1, p + 1 + n, cmp);

	up.pb(p[1]);
	down.pb(p[1]);

	ll top = 0, bot = 0;
	for (int i = 2; i <= n; i ++)
	{
		while (up.size() >= 2)
		{
			pt A = up[sz(up) - 2], B = up[sz(up) - 1];
			pt a = pt(B.x - A.x, B.y - A.y);
			pt b = pt(p[i].x - A.x, p[i].y - A.y);
			if (a.vect(b) < 0) break;
			top -= up[sz(up) - 2].trap(up[sz(up) - 1]);
			up.pop_back();
		}
		top += up[sz(up) - 1].trap(p[i]);
		up.pb(p[i]);
		while (down.size() >= 2)
		{
			pt A = down[sz(down) - 2], B = down[sz(down) - 1];
			pt a = pt(B.x - A.x, B.y - A.y);
			pt b = pt(p[i].x - A.x, p[i].y - A.y);
			if (a.vect(b) > 0) break;
			bot -= down[sz(down) - 2].trap(down[sz(down) - 1]);
			down.pop_back();
		}
		bot += down[sz(down) - 1].trap(p[i]);
		down.pb(p[i]);
		pref[i] = top - bot;
	}

	//sort(p + 1, p + 1 + n, cmp2);
	reverse(p + 1, p + 1 + n);

	up.clear();
	down.clear();
	up.pb(p[1]);
	down.pb(p[1]);

	top = 0, bot = 0;
	for (int i = 2; i <= n; i ++)
	{
		while (up.size() >= 2)
		{
			pt A = up[sz(up) - 2], B = up[sz(up) - 1];
			pt a = pt(B.x - A.x, B.y - A.y);
			pt b = pt(p[i].x - A.x, p[i].y - A.y);
			if (a.vect(b) < 0) break;
			top -= up[sz(up) - 2].trap(up[sz(up) - 1]);
			up.pop_back();
		}
		top += up[sz(up) - 1].trap(p[i]);
		up.pb(p[i]);
		while (down.size() >= 2)
		{
			pt A = down[sz(down) - 2], B = down[sz(down) - 1];
			pt a = pt(B.x - A.x, B.y - A.y);
			pt b = pt(p[i].x - A.x, p[i].y - A.y);
			if (a.vect(b) > 0) break;
			bot -= down[sz(down) - 2].trap(down[sz(down) - 1]);
			down.pop_back();
		}
		bot += down[sz(down) - 1].trap(p[i]);
		down.pb(p[i]);
		suff[i] = top - bot;
	}

	reverse(suff + 1, suff + 1 + n);
	//sort(p + 1, p + 1 + n, cmp);
	reverse(p + 1, p + n + 1);

	ll ans = 9 * (ll)1e18;
	p[0] = p[1];
	//for (int i = 1; i <= n; i ++) p[i].print();
	for (int i = 1; i <= n; i ++)
	{
		if (p[i].x == p[i - 1].x) continue;
		//cout << pref[i - 1] << " % " << suff[i] << "\n";
		ans = min(ans, pref[i - 1] + suff[i]);
	}

	cout << (ans + 1) / 2 << "\n";
}


