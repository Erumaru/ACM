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

struct edge
{
	int a, b, cap, flow;
	edge(){}
	edge(int a, int b, int cap, int flow) : a(a), b(b), cap(cap), flow(flow) {} 
};

vector <int> g[210];
vector <edge> e;
int n, s, t, q[210], d[210], ptr[210];

void add_edge(int a, int b, int cap)
{
	g[a].pb(sz(e));
	e.pb(edge(a, b, cap, 0));
	g[b].pb(sz(e));
	e.pb(edge(b, a, 0, 0));
}

bool bfs()
{
	int qh = 0, qt = 0;
	memset(d, -1, sizeof d);
	q[qt ++] = s;
	d[s] = 0;
	while (qh < qt && d[t] == -1)
	{
		int v = q[qh ++];
		for (int i = 0; i < sz(g[v]); i ++)
		{
			int id = g[v][i], to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap)
			{
				q[qt ++] = to;
				d[to] = d[v] + 1;
			}
		}
	}

	return d[t] != -1;
}

int dfs(int v, int flow)
{
	if (flow == 0) return 0;
	if (v == t) return flow;
	for (; ptr[v] < sz(g[v]); ptr[v] ++)
	{
		int id = g[v][ptr[v]], to = e[id].b;
		if (d[to] != d[v] + 1) continue;
		int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
		if (pushed)
		{
			e[id].flow += pushed;
			e[id ^ 1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic()
{
	int flow = 0;
	while (bfs())
	{
		memset(ptr, 0, sizeof ptr);
		int pushed;
		while (pushed = dfs(s, inf))
		{
			flow += pushed;
		}
	}
	return flow;
}

void solve()
{
	cin >> n;
	s = 1, t = n;
	for (int i = 1, k; i < n; i ++)
	{
		cin >> k;
		for (int j = 1, x; j <= k; j ++)
		{
			cin >> x;
			int cap = 1;
			if (i != 1 && x != n) cap = inf;
			add_edge(i, x, cap);
		}
	}

	
	cout << dinic() << " ";
	for (int i = 1; i <= n; i ++) g[i].clear();
	e.clear();

}

int test;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        
	cin >> test;
	for (int i = 1; i <= test; i ++) solve();
}


