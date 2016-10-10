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

int n, m;
string s;
pii t[400100], p[100100];
int sum[400100];
vector <int> ans;

void build (int v, int tl, int tr)
{
	if (tl == tr) t[v] = p[tl];
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		t[v] = min(t[2 * v], t[2 * v + 1]);	
	}
}

void update(int v, int tl, int tr, int pos, pii x)
{
	if (tl == tr) t[v] = x;
	else
	{
		int mid = (tl + tr) / 2;
		if (pos <= mid) update(2 * v, tl, mid, pos, x);
		else update(2 * v + 1, mid + 1, tr, pos, x);
		t[v] = min(t[2 * v], t[2 * v + 1]);
	}
}

pii get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return mp(inf, inf);
	if (tl >= l && tr <= r) return t[v];
	int mid = (tl + tr) / 2;
	return min(get(2 * v, tl, mid, l, r), get(2 * v + 1, mid + 1, tr, l, r));
}

int getSum(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return sum[v];
	int mid = (tl + tr) / 2;
	return getSum(2 * v, tl, mid, l, r) + getSum(2 * v + 1, mid + 1, tr, l, r); 
}
void inc(int v, int tl, int tr, int pos)
{
	if (tl == tr) sum[v] = 1;
	else
	{
		int mid = (tl + tr) / 2;
		if (pos <= mid) inc(2 * v, tl, mid, pos);
		else inc(2 * v + 1, mid + 1, tr, pos);
		sum[v] = sum[2 * v] + sum[2 * v + 1];
	}
}

int main ()
{      
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m;
	cin >> s;
	n = sz(s);
	for (int i = 1; i <= n; i ++)
	{
		p[i] = mp(s[i - 1], i);
	}

	build(1, 1, n);

	int mx = 0;
	for (int i = n - m + 1; i >= 1; i --)
	{
		if (getSum(1, 1, n, i, i + m - 1) > 0) continue;
		pii cur = get(1, 1, n, i, i + m - 1);
		mx = max(mx, cur.ft);
		update(1, 1, n, cur.st, mp(inf, inf));
		inc(1, 1, n, cur.st);
		ans.pb(cur.ft);
		//cout << i << " " << i + m - 1 << " " << char(cur.ft) << " " << cur.st<< "\n";
	}

	for (int i = 1; i <= n; i ++)
	{
		if (s[i - 1] >= mx) continue;
		if (getSum(1, 1, n, i, i) == 0) ans.pb(s[i - 1]);
	}

	sort(all(ans));

	for (int i = 0; i < sz(ans); i ++) cout << char(ans[i]);
}


