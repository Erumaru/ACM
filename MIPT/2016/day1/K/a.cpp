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

int dfs(int v, int p)
{
	int res = 0;
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i].s;
		if (to == p) continue;
		if (del[to]) continue;
		res += dfs(to, v);
	}

	return sz[v] = res + 1;
}

int centr(int v, int p, int cur)
{
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i].s;
		if (to == p) continue;
		if (sz[to] < cur / 2) continue;
		if (del[to]) continue;
		return centr(to, v, cur);
	}
	return v;
}

void go(int v)
{
	dfs(v, -1);
	v = centr(v, -1, sz[v]);
	del[v] = true;
	now.clear();
	calc(v, -1, 0);

}

int main ()
{      
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", c + i);
	for (int i = 1, a, b, d; i < n; i ++)
	{
		scanf("%d%d", &a, &b);
		g[a].pb(mp(d, b));
		g[b].pb(mp(d, a));
	}

	go(1);
}


