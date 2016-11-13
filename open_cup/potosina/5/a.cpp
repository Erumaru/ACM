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
typedef pair<ll, ll> pii;

const int N = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

struct edge
{
	ll a, b, flow, cap, cost;
	edge() {}
	edge(ll a, ll b, ll cap, ll cost) : a(a), b(b), cap(cap), cost(cost) {flow = 0;}
};

vector <edge> e;
vector <int> g[250];
queue <pii> q;
ll d[250], phi[250], a[250][50], n, k, id, from[250], p[250], cnt;

void add_edge(ll a, ll b, ll cap, ll cost)
{
	g[a].pb(sz(e));
	e.pb(edge(a, b, cap, cost));
	g[b].pb(sz(e));
	e.pb(edge(b, a, 0, -cost));
}

ll ford_bellman()
{
	for (int i = 0; i <= n + k + 3; i ++) d[i] = INF, from[i] = -1;
	d[0] = 0;
	for (int i = 1; i <= n + k + 3; i ++)
	{
		bool changed = false;
		for (int j = 0; j < sz(e); j ++)
		{
			int a = e[j].a, b = e[j].b, len = e[j].cost;
			if (e[j].flow == e[j].cap) continue;
			if (d[a] + len < d[b])
			{
				d[b] = d[a] + len;
				from[b] = j;
				changed = true;
			}
		}
		if (!changed) break;
	}

	return d[n + k + 3];
}

ll go(int x)
{
	ll res = 0;
	e.clear();
	for (int i = 0; i <= n + k + 3; i ++) g[i].clear();
	for (int i = 1; i <= n; i ++)
	{
		add_edge(0, i, 1, 0);
		for (int j = 1; j <= k + 1; j ++) add_edge(i, n + j, 1, a[i][j]);
	}
	for (int i = 1; i <= k; i ++)
	{
		if (i == id) continue;
		add_edge(n + i, n + k + 2, x - 1, 0);
	}
	add_edge(n + id, n + k + 3, 500, 0);
	add_edge(n + k + 1, n + k + 2, 500, 0);
	add_edge(n + k + 2, n + k + 3, n - x, 0);

	while (true)
	{	
		ll cost = ford_bellman();
		//cerr << cost << " ";
		if (cost == INF) break;
		ll mn = INF;
		for (int i = from[n + k + 3]; i != -1; i = from[e[i].a])
		{
			mn = min(mn, e[i].cap - e[i].flow);
		}
		for (int i = from[n + k + 3]; i != -1; i = from[e[i].a])
		{
			e[i].flow += mn;
			e[i ^ 1].flow -= mn;
			res += mn * e[i].cost;
		}
	}

	return res;
}

int main ()
{
	scanf("%lld%lld%lld", &n, &k, &id);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= k + 1; j ++)
		{	
			scanf("%lld", &a[i][j]);
		}
	}

	ll ans = INF, q;
	for (int i = 1; i <= n; i ++) 
	{
		ll cur = go(i);
		if (cur < ans)
		{
			ans = cur;
			q = i;
		}
	}

	ans = go(q);
	for (int j = 0; j < sz(e); j ++)
	{
		if (e[j].b == n + k + 3) continue;
		if (e[j].a == 0) continue;
		if (e[j].b == n + k + 2) continue;
		if (e[j].flow == 0) continue;
		if (e[j].cap == 0) continue;
		//cout << e[j].a << " " << e[j].b - n << " " << e[j].flow << "\n";
		p[e[j].a] = e[j].b - n;
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i ++) cout << p[i] << " ";
	cout << endl;
}


