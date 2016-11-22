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

vector <int> g[500100], rev[500100], order, comp[500100], ans;
int a[1000100], b[1000100], n, m, col[500100], in[500100], id[500100], t[2000100][3];
bool u[500100], bad[500100];

void topsort(int v)
{
	if (u[v]) return;
	u[v] = true;
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		topsort(to);
	}
	order.pb(v);
}

void topsort2(int v)
{
	if (u[v]) return;
	u[v] = true;
	for (int i = 0; i < sz(rev[v]); i ++)
	{
		int to = rev[v][i];
		topsort2(to);
	}
	order.pb(v);
}

void make_comp(int v, int color)
{
	if (u[v]) return;
	u[v] = true;
	col[v] = color;
	comp[color].pb(v);
	for (int i = 0; i < sz(rev[v]); i ++)
	{
		int to = rev[v][i];
		make_comp(to, color);
	}
}

void build (int v, int tl, int tr)
{
	if (tl == tr) 
	{
		t[v][1] = in[tl];
	}
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		for (int i = 1; i <= 2; i ++) t[v][i] = min(t[2 * v][i], t[2 * v + 1][i]);  
	}
}

void update(int v, int tl, int tr, int pos, int x, int p)
{
	if (tl == tr) t[v][p] += x;
	else
	{
		int mid = (tl + tr) / 2;
		if (pos <= mid) update(2 * v, tl, mid, pos, x, p);
		else update(2 * v + 1, mid + 1, tr, pos, x, p);
		t[v][p] = min(t[2 * v][p], t[2 * v + 1][p]);
	}
}

int get(int v, int tl, int tr, int l, int r, int p)
{
	if (tl > r || tr < l) return inf;
	if (tl >= l && tr <= r) return t[v][p];
	int mid = (tl + tr) / 2;
	int ans1 = get(2 * v, tl, mid, l, r, p);
	int ans2 = get(2 * v + 1, mid + 1, tr, l, r, p);
	return min(ans1, ans2);
}

int main ()
{      
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d%d", a + i, b + i);
		g[a[i]].pb(b[i]);
		rev[b[i]].pb(a[i]);
	}

	for (int i = 1; i <= n; i ++)
	{
		topsort(i);
	}	

	reverse(all(order));
	memset(u, false, sizeof u);
	int p = 0;
	for (int i = 0; i < sz(order); i ++)
	{
		int v = order[i];
		if (u[v]) continue;
		p ++;
		make_comp(v, p);
	}

	for (int i = 1; i <= n; i ++) 
	{
		g[i].clear();
		rev[i].clear();
	}

	for (int i = 1; i <= m; i ++)
	{
		if (col[a[i]] == col[b[i]]) continue;
		g[col[a[i]]].pb(col[b[i]]);
		rev[col[b[i]]].pb(col[a[i]]);
	}

	for (int i = 1; i <= p; i ++)
	{
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
		sort(all(rev[i]));
		rev[i].resize(unique(all(rev[i])) - rev[i].begin()); 
	}

	order.clear();
	memset(u, false, sizeof u);
	for (int i = 1; i <= p; i ++)
	{
		topsort(i);
	}

	reverse(all(order));

	for (int i = 0; i < sz(order); i ++) id[order[i]] = i + 1;

	for (int i = 1; i <= p; i ++)
	{
		for (int j = 0; j < sz(g[i]); j ++) 
		{
			int v = g[i][j];
			in[id[v]] ++;
		}
	}

 	n = sz(order);
	build(1, 1, n);

	for (int i = 0; i < n; i ++)
	{
		int v = id[order[i]];
		int cur = get(1, 1, n, v + 1, n, 1);
		if (cur == 0) bad[order[i]] = true;
		for (int j = 0; j < sz(g[order[i]]); j ++)
		{
			int to = id[g[order[i]][j]];
			update(1, 1, n, to, -1, 1);
		}
	}

	order.clear();
	memset(u, false, sizeof u);
	for (int i = 1; i <= p; i ++)
	{
		topsort2(i);
	}
	for (int i = 1; i <= p; i ++)
	{
		cout << i << ":\n";
		for (int j = 0; j < sz(comp[i]); j ++)
		{
			cout << comp[i][j] << " ";
		}
		cout << endl;
	}

	reverse(all(order));
	for (int i = 0; i < sz(order); i ++) cout << order[i] << " ";
		cout << endl;

	for (int i = 0; i < sz(order); i ++) id[order[i]] = i + 1;

	for (int i = 1; i <= p; i ++) in[i] = 0;
	for (int i = 1; i <= p; i ++)
	{
		for (int j = 0; j < sz(rev[i]); j ++) 
		{
			int v = rev[i][j];
			in[id[v]] ++;
		}
	}

	build(1, 1, n);

	for (int i = 0; i < n; i ++)
	{
		int v = id[order[i]];
		int cur = get(1, 1, n, v + 1, n, 1);
		if (cur == 0) bad[order[i]] = true;
		for (int j = 0; j < sz(rev[order[i]]); j ++)
		{
			int to = id[rev[order[i]][j]];
			update(1, 1, n, to, -1, 1);
		}
	}

	for (int i = 1; i <= p; i ++) 
	{
		if (bad[i]) continue;
		for (int j = 0; j < sz(comp[i]); j ++)
		{
			int cur = comp[i][j];
			ans.pb(cur);
		}
	}



	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i ++) printf("%d ", ans[i]);

}


