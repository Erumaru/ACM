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
	edge(int a, int b, ll cap) : a(a), b(b), cap(cap) {flow = 0;}
};

vector <int> g[300010];
vector <edge> e;
int s, t, n, m, b[60][60], w[60][60], p[50100][10], r, ptr[300010], d[300010], q[300010], 
	table[5][10][10][60][60], id[60][60], two[60];

void add_edge(int a, int b, ll cap)
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

int main ()
{      
	scanf("%d%d%d", &n, &m, &r);

	s = 1, t = 2;
	int cur = 3;
	ll sum = 0;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			id[i][j] = cur ++;
			table[1][0][0][i][j] = cur ++;
			table[0][0][0][i][j] = cur ++;
			add_edge(table[1][0][0][i][j], id[i][j], INF);
			add_edge(id[i][j], table[0][0][0][i][j], INF);
		}
	}

	for (int lvl1 = 0; (1 << lvl1) <= n; lvl1 ++)
	{
		for (int lvl2 = 0; (1 << lvl2) <= m; lvl2 ++)
		{
			if (lvl1 == 0 && lvl2 == 0) continue;
			for (int i = 1; i + (1 << lvl1) - 1 <= n; i ++)
			{
				for (int j = 1; j + (1 << lvl2) - 1 <= m; j ++)
				{
					if (lvl1 > lvl2)
					{
						table[1][lvl1][lvl2][i][j] = cur ++;
						add_edge(table[1][lvl1][lvl2][i][j], table[1][lvl1 - 1][lvl2][i][j], INF);
						add_edge(table[1][lvl1][lvl2][i][j], table[1][lvl1 - 1][lvl2][i + (1 << (lvl1 - 1))][j], INF);
						table[0][lvl1][lvl2][i][j] = cur ++;
						add_edge(table[0][lvl1 - 1][lvl2][i][j], table[0][lvl1][lvl2][i][j], INF);
						add_edge(table[0][lvl1 - 1][lvl2][i + (1 << (lvl1 - 1))][j], table[0][lvl1][lvl2][i][j], INF);
					}
					else
					{
						table[1][lvl1][lvl2][i][j] = cur ++;
						add_edge(table[1][lvl1][lvl2][i][j], table[1][lvl1][lvl2 - 1][i][j], INF);
						add_edge(table[1][lvl1][lvl2][i][j], table[1][lvl1][lvl2 - 1][i][j + (1 << (lvl2 - 1))], INF);
						table[0][lvl1][lvl2][i][j] = cur ++;
						add_edge(table[0][lvl1][lvl2 - 1][i][j], table[0][lvl1][lvl2][i][j], INF);
						add_edge(table[0][lvl1][lvl2 - 1][i][j + (1 << (lvl2 - 1))], table[0][lvl1][lvl2][i][j], INF);
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++) 
		{
			scanf("%d", &b[i][j]);
			add_edge(s, cur, b[i][j]);
			add_edge(cur, table[1][0][0][i][j], INF);
			cur ++;
			sum += b[i][j];
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			scanf("%d", &w[i][j]);
			add_edge(cur, t, w[i][j]);
			add_edge(table[0][0][0][i][j], cur, INF);
			cur ++;
			sum += w[i][j];
		}
	}

	two[0] = -1;
	for (int i = 1; i <= max(n, m); i ++) two[i] = two[i / 2] + 1;

	for (int i = 1; i <= r; i ++)
	{
		for (int j = 1; j <= 6; j ++) 
		{
			scanf("%d", &p[i][j]);
		}
		int lvl1 = two[p[i][3] - p[i][1] + 1], lvl2 = two[p[i][4] - p[i][2] + 1];
		int x = p[i][1], x2 = p[i][3], y = p[i][2], y2 = p[i][4];
		if (p[i][5])
		{
			add_edge(s, cur, p[i][6]);
			add_edge(cur, table[1][lvl1][lvl2][x][y], INF);
			add_edge(cur, table[1][lvl1][lvl2][x2 - (1 << lvl1) + 1][y], INF);
			add_edge(cur, table[1][lvl1][lvl2][x][y2 - (1 << lvl2) + 1], INF);
			add_edge(cur, table[1][lvl1][lvl2][x2 - (1 << lvl1) + 1][y2 - (1 << lvl2) + 1], INF);
		}
		else
		{
			add_edge(cur, t, p[i][6]);
			add_edge(table[0][lvl1][lvl2][x][y], cur, INF);
			add_edge(table[0][lvl1][lvl2][x2 - (1 << lvl1) + 1][y], cur, INF);
			add_edge(table[0][lvl1][lvl2][x][y2 - (1 << lvl2) + 1], cur, INF);
			add_edge(table[0][lvl1][lvl2][x2 - (1 << lvl1) + 1][y2 - (1 << lvl2) + 1], cur, INF);
		}
		cur ++;
		sum += p[i][6];
	}

	cout << sum - dinic();
		
}


