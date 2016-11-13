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

pair <ll, ll> t[400100], d[100100];
ll a[100100], b[100100], c[100100], pos[100100], sum[400100], p[100100], n, L;
int ans = inf; 

void build (int v, int tl, int tr)
{
	if (tl == tr) 
	{
		t[v] = mp(a[d[tl].s], -tl);
		sum[v] = d[tl].f - c[tl - 1];
	}
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		t[v] = max(t[2 * v], t[2 * v + 1]);
		sum[v] = min(sum[2 * v], sum[2 * v + 1]);
	}
}

ll getsum (int v, int tl, int tr, int l, int r)
{	
	if (tl > r || tr < l) return INF;
	if (tl >= l && tr <= r) return sum[v];
	int mid = (tl + tr) / 2;
	ll ans1 = getsum(2 * v, tl, mid, l, r);
	ll ans2 = getsum(2 * v + 1, mid + 1, tr, l, r);
	return min(ans1, ans2);
}

pair <ll, ll> get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return mp(-inf, -inf);
	if (tl >= l && tr <= r) return t[v];
	int mid = (tl + tr) / 2;
	pair <ll, ll> ans1 = get(2 * v, tl, mid, l, r);
	pair <ll, ll> ans2 = get(2 * v + 1, mid + 1, tr, l, r);
	return max(ans1, ans2);
}

bool ok (int x)
{
	for (int i = 1; i < x; i ++)
	{
		ll cur = getsum(1, 1, n, i + 1, x);
		
		if (cur > p[d[i].s] && a[d[i].s] + d[x].f - p[d[i].s] >= L) 
		{
			//cout << cur << " " << p[d[i].s] << " " << i << " " << x << " "
			//<< d[x].f << " " << a[d[i].s] << "\n";
 			return true;
		}
		if (d[i].f <= c[i]) return false;
	}
	return false;
}

int main ()
{      
	scanf("%lld%lld", &n, &L);
	for (int i = 1; i <= n; i ++) 
	{
		scanf("%lld%lld", a + i, b + i);
		d[i] = mp(a[i] - b[i], i);	
		p[i] = a[i] - b[i];
	}

	for (int i = 1; i <= n; i ++) 
	{
		scanf("%lld", c + i);
		c[i] += c[i - 1];
	}

	for (int i = 1; i <= n; i ++)
	{
		if (a[i] >= L) 
		{
			cout << 1;
			return 0;
		}
	}

	sort(d + 1, d + n + 1);
	reverse(d + 1, d + n + 1);

	for (int i = 1; i <= n; i ++)
	{
		d[i].f += d[i - 1].f;
		pos[d[i].s] = i;
	}

	build (1, 1, n);

	for (int i = 1; i < n; i ++)
	{
		if (d[i].f <= c[i]) break;
		ll cur = get(1, 1, n, i + 1, n).f;
		if (d[i].f + cur >= L) ans = min(ans, i + 1);
	}

	for (int i = 1; i <= n; i ++)
	{
		if (p[d[i].s] <= 0) 
		{
			n = i - 1;
			assert(false);
			break;
		}
	}

	int l = 1, r = min(n, (ll)ans-1);

	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (ok(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}

	if (ans == inf) cout << -1 << "\n"; 
	else cout << ans << "\n";
}


