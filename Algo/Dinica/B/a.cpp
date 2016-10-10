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

edge e[500100];
int sz = 0;
vector <int> g[100010];
int ptr[100010], q[100010], d[100010], n, m, s, t, p, lim; 

void add_edge(int a, int b, int cap)
{
	g[a].pb(sz);
	e[sz ++] = edge(a, b, cap, 0);
	g[b].pb(sz);
	e[sz ++] = edge(b, a, 0, 0);
}

bool bfs()
{
	int qh = 0, qt = 0;
	memset(d, -1, sizeof d);
	d[s] = 0;
	q[qt ++] = s;
	while (qh < qt && d[t] == -1)
	{
		int v = q[qh ++];
		for (int i = 0; i < sz(g[v]); i ++)
		{
			int id = g[v][i], to = e[id].b;
			if (d[to] == -1 && e[id].cap - e[id].flow > 0)
			{
				d[to] = d[v] + 1;
				q[qt ++] = to;
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
		int pushed = 0;
		memset(ptr, 0, sizeof ptr);
		while (pushed = dfs(s, inf)) flow += pushed;
	}

	return flow;
}

int bull(int x)
{
	return n + x;
}

int main ()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i ++) add_edge(0, i, 1);
	for (int i = 1, a, b; i <= p; i ++)
	{
		scanf("%d%d", &a, &b);
		add_edge(a, bull(b), 1);
	}      
	for (int i = 1; i <= m; i ++) add_edge(bull(i), n + m + 1, 1);
	s = 0, t = n + m + 1;
	cout << dinic() << " "; 

}


