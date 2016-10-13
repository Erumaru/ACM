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

vector <int> g[1010];
bool u[1010];
int col[1010], n, m, k;

int dfs (int v)
{
	if (u[v]) return 0;
	u[v] = true;
	int res = 0;
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		res = max(res, dfs(to));
	}
	return res + 1;
}

void color(int v, int c)
{
	if (col[v] != 0) return;
	col[v] = c;
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		color(to, c + 1);
	}
}

bool path(int v, int lvl)
{
	if (u[v]) return false;
	u[v] = true;
	if (lvl == k + 1)
	{
		printf("%d ", v);
		return true;
	}

	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		if (path(to, lvl + 1))
		{
			printf("%d ", v);
			return true;
		}
	}
	return false;
}

void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++) 
	{
		u[i] = false;
		g[i].clear();
		col[i] = 0;
	}

	for (int i = 1, a, b; i <= m; i ++)
	{
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}

	int mx = 0, id = -1;
	for (int i = 1; i <= n; i ++)
	{
		if (u[i]) continue;
		int cur = dfs(i);
		if (cur > mx)
		{
			mx = cur;
			id = i;
		}
	}

	if (mx <= k)
	{
		printf("coloring\n");
		for (int i = 1; i <= n; i ++)
		{
			if (col[i] == 0) color(i, 1);		
		}

		for (int i = 1; i <= n; i ++) printf("%d ", col[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i ++) u[i] = false;
	printf("path\n");
	path(id, 1);
	printf("\n");
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();
}


