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

int mx, n, id;
vector <int> g[10010];

void dfs(int v, int p, int lvl)
{
	if (mx < lvl)
	{
		mx = lvl;
		id = v;
	}
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		if (to != p)
		{
			dfs(to, v, lvl + 1);
		}
	}
}

int main ()
{      
	scanf("%d", &n);
	for (int i = 1, a, b; i < n; i ++)
	{
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}	
	dfs(1, -1, 0);
	mx = 0;
	dfs(id, -1, 0);
	printf("%d", mx);
}


