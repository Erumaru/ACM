//#pragma comment(linker, "/STACK:64000000")
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

const int MAXN = 201;
const int INF = 1000000000; 
 
struct edge {
	int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN], lvl[MAXN], m;
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int fake(int x)
{
	return n + x;
}

void solve()
{
	cin >> n >> m;
	e.clear();
	s = 0;
	t = 2 * n + 1;
	for (int i = 1; i <= 2 * n + 1; i ++)
	{
		g[i].clear();
		lvl[i] = 0;
	}
	for (int i = 1, a, b; i <= m; i ++)
	{
		cin >> a >> b;
		lvl[a] ++;
		lvl[b] ++;
		add_edge(a, fake(b), 1);
		add_edge(b, fake(a), 1);
	}

	for (int i = 1; i <= n; i ++)
	{
		int cap;
		if (lvl[i] & 1) cap = lvl[i];
		else cap = lvl[i] / 2;
		add_edge(0, i, cap);
		add_edge(fake(i), 2 * n + 1, cap);
	}

	dinic();

	int ans = n; 
	for (int i = 1; i <= n; i ++) if (lvl[i] & 1) ans --;

	cout << ans << "\n";
	for (int i = 0; i < sz(e); i ++)
	{
		if (e[i].cap == 0) continue;
		if (e[i].a == 0) continue;
		if (e[i].b == 2 * n + 1) continue;
		if (e[i].flow == 0) continue; 
		cout << e[i].a << " " << e[i].b - n << "\n";
	}
}

int test;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        

	cin >> test;
	for (int i = 1; i <= test; i ++) solve();
}


