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

int n, k, a[100100], b[100100], col[100100], d[100100], pos[100100];
vector <int> g[100100];
bool u[100100];

void coloring(int v, int color)
{
	if (col[v] != 0) return;
	col[v] = color;
	int next = d[b[v]];
	pos[v] = sz(g[color]);
	g[color].pb(v);
	coloring(next, color);
}

int main ()
{      
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) 
	{
		scanf("%d%d", a + i, b + i);
		d[a[i]] = i;
	}
	int comp = 1;
	for (int i = 1; i <= n; i ++)
	{
		if (col[i] == 0)
		{
			coloring(i, comp);
			comp ++;
		}
	}

	for (int i = 1, x, T; i <= k; i ++)
	{	
		scanf("%d%d", &x, &T);
		int cur = col[x];
		int len = sz(g[cur]);
		int ans = g[cur][(pos[x] + T) % len];
		printf("%d\n", ans);
	}	
}


