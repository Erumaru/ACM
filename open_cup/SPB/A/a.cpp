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
typedef pair <ll, ll> pii;

const int N = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

set <pii> st;
ll n, ss, a[200100];
__int128 p[200100], s;
int t[1600100];

vector <__int128> v;
map <__int128, int> id;

void build(int v, int tl, int tr)
{
	if (tl == tr) t[v] = inf;
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		t[v] = min(t[2 * v], t[2 * v + 1]);
	}
}

int get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return inf;
	if (tl >= l && tr <= r) return t[v];
	int mid = (tl + tr) / 2;
	return min(get(2 * v, tl, mid, l, r), get(2 * v + 1, mid + 1, tr, l, r));
}

void update(int v, int tl, int tr, int pos, int x)
{
	if (tl == tr) t[v] = min(t[v], x);
	else
	{
		int mid = (tl + tr) / 2;
		if (pos <= mid) update(2 * v, tl, mid, pos, x);
		else update(2 * v + 1, mid + 1, tr, pos, x);
		t[v] = min(t[2 * v], t[2 * v + 1]);
	}
}

int main ()
{      
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> ss;
	s = ss;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
		v.pb(p[i]);
		v.pb(p[i] - s);
		//cout << ll(p[i]) << " ";
	}
	//cout << endl;

	sort(all(v));
	v.resize(unique(all(v)) - v.begin());

	for (int i = 0; i < sz(v); i ++) id[v[i]] = i + 1;
	int sz = sz(v);

	build(1, 1, sz);

	int ans = 0, L = inf, R = inf;
	bool ok = false;
	for (int i = 1; i <= n; i ++)
	{
		if (p[i] > s)
		{
			int cur = get(1, 1, sz, id[p[i] - s], sz);
			//cout << i << " " << cur << "\n";
			if (cur != inf)
			{
				ok = true;
				if (i - cur > ans)
				{
					ans = i - cur;
					L = cur + 1; 
					R = i;
				}
				else if (i - cur == ans)
				{
					if (L > cur + 1)
					{
						L = cur + 1;
						R = i;
					}
				}
			}
		}
		else
		{
			ok = true;
			ans = i;
			L = 1;
			R = i;
		}
		update(1, 1, sz, id[p[i]], i);
	}

	if (!ok) 
	{
		cout << -1;
	}
	else
	{
		cout << ans << "\n";
		cout << L - 1 << " " << n - R;
	}


}


