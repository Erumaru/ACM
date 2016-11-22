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

struct edge
{	
	ll a, b, flow, cap;
	edge(){}
	edge(int a, int b, int cap) : a(a), b(b), cap(cap) {}
};

vector <int> g[210];
vector <edge> e;
int s, t, n, m, b[60][60], w[60][60], p[50100][10], r, ptr[210], d[210], q[210];

void add_edge(int a, int b, int cap)
{
	g[a].pb(sz(e));
	e.pb(edge(a, b, cap));
	g[b].pb(sz(e));
	e.pb(edge(b, a, 0));
}


bool bfs()
{
	int qt = 0, qh = 0;
	memset(d, -1, sizeof d);
	d[s] = 0;
	q[qt ++] = s;
	while (qh < qt && d[t] == -1)
	{
		int v = q[qh ++];
		for (int i = 0; i < sz(g[v]); i ++)
		{
			int id = g[v][i], to = e[id].b;
			if (e[id].flow == e[id].cap) continue;
			if (d[to] != -1) continue;
			q[qt ++] = to;
			d[to] = d[v] + 1;
		}
	}

	return d[t] != -1;
}

ll dfs(int v, ll flow)
{	
	if (flow == 0) return 0;
	if (v == t) return flow;
	for (; ptr[v] < sz(g[v]); ptr[v] ++)
	{
		int i = ptr[v];
		int id = g[v][i], to = e[id].b;
		if (d[to] != d[v] + 1) continue;
		ll push = dfs(to, min(flow, e[id].cap - e[id].flow));
		if (push)
		{
			e[id].flow += push;
			e[id ^ 1].flow -= push;
			return push;
		}
	}

	return 0;
}

ll dinic()
{
	ll res = 0;
	while (bfs())
	{
		ll push;
		memset(ptr, 0, sizeof ptr);
		while (push = dfs(s, INF))
		{
			res += push;
		}
	}

	return res;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) g[i].clear();
	e.clear();
	s = 1, t = n;
	for (int i = 1, k; i < n; i ++)
	{
		scanf("%d", &k);
		for (int j = 1, x; j <= k; j ++)
		{
			scanf("%d", &x);
			if (i == 1 || x == n) add_edge(i, x, 1);
			else add_edge(i, x, inf);
		}
	}

	printf("%lld\n", dinic());

}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();
}


