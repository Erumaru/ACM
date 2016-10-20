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

int n, m, col[2010];
vector <int> g[2010];
bool ok;

void dfs(int v, int color)
{
	if (col[v] != -1) return;
	if (!ok) return;
	col[v] = color;

	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		dfs(to, color ^ 1);
	}

	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		if (col[v] == col[to])
		{
			ok = false;
			return;
		}
	}
}

void solve(int test)
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		g[i].clear();
		col[i] = -1;
	}
	for (int i = 1, a, b; i <= m; i ++)
	{
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}

	for (int i = 1; i <= n; i ++)
	{
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
	}

	ok = true;
	for (int i = 1; i <= n; i ++) dfs(i, 0);	

	if (!ok) printf("Scenario #%d:\nSuspicious bugs found!\n", test);
	else printf("Scenario #%d\nNo suspicious bugs found!\n", test);
}

int q;

int main ()
{      
	scanf("%d", &q);
	for (int i = 1; i <= q; i ++) solve(i);
}


