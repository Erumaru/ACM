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
typedef pair <ll, ll> pll;

const int N = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

int T;
vector <int> g[100100],  d[100100], cur, L;
vector <pll> gg[5001000];
priority_queue <pll> q;
ll dp[5000100], lvl[100100], sz[100100], centr;
int n, m, qq, c[100100], w[100100], x[100100];
bool del[100100];

bool cmp(int i, int j)
{
	return lvl[i] < lvl[j];
}

int dfs(int v, int p, int l)
{	
	lvl[v] = l;
	int res = 0;
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		if (del[to]) continue;
		if (to == p) continue;
		res += dfs(to, v, l + 1);
	}
	cur.pb(v);

	return sz[v] = res + 1;
}

void centroid(int v, int p, int pr)
{

	bool ok = true;
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		if (del[to]) continue;
		if (to == pr) continue;
		if (sz[to] > p / 2)
		{
			return centroid(to, p, v);
			ok = false;
		}
	}
	if (ok) centr = v;
}	

void go(int v)
{
	cur.clear();
	dfs(v, -1, 0);
	centroid(v, sz[v], -1);
	v = centr;
	cur.clear();
	dfs(v, -1, 0);
	del[v] = true;
	sort(all(cur), cmp);
	int start = T;
	L.clear();
	for (int i = 0; i < sz(cur); i ++)
	{
		int now = cur[i];
		gg[now].pb(mp(0, T));
		if (i) gg[T - 1].pb(mp(0, T));
		T ++;
		L.pb(lvl[now]);
	}

	for (int i = 0; i < sz(cur); i ++)
	{
		int now = cur[i];
		for (int j = 0; j < sz(d[now]); j ++)
		{
			int id = d[now][j];
			int l = x[id] - lvl[now];
			int h = upper_bound(all(L), l) - L.begin() - 1;
			if (h < 0) continue;
			gg[start + h].pb(mp(w[id], now));
		}
	}
	for (int i = 0; i < sz(g[v]); i ++) 
	{
		int to = g[v][i];
		if (del[to]) continue;
		go(to);
	}

}

int main ()
{      
	scanf("%d%d%d", &n, &m, &qq);
	for (int i = 1, a, b; i < n; i ++)
	{
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}	
	T = n + 1;

	for (int i = 1; i <= m; i ++)
	{
		scanf("%d%d%d", c + i, x + i, w + i);
		d[c[i]].pb(i);
	}

	go(1);

	for (int i = 0; i <= T; i ++) dp[i] = INF;
	dp[1] = 0;
	q.push(mp(0, 1));
	while (!q.empty())
	{
		pll now = q.top();
		q.pop();
		ll cost = -now.f, v = now.s;
		if (cost != dp[v]) continue;
		for (int i = 0; i < sz(gg[v]); i ++)
		{
			int to = gg[v][i].s, len = gg[v][i].f;
			if (dp[to] > dp[v] + len)
			{
				dp[to] = dp[v] + len;
				q.push(mp(-dp[to], to));
			}	
		}
	}

	for (int i = 1, x; i <= qq; i ++)
	{
		scanf("%d", &x);
		if (dp[x] == INF) cout << "Impossible\n";
		else cout << dp[x] << "\n";

	}	
}


