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

ll t[400100], add[400100];
int n, m;

void build (int v, int tl, int tr)
{
	if (tl == tr) t[v] = 0, add[v] = 0;
	else
	{
		int mid = (tl + tr) / 2; 
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		t[v] = 0;
		add[v] = 0;
	}
}

void push(int v, int tl, int tr)
{
	t[v] += add[v] * (tr - tl + 1);
	if (tl != tr) 
	{
		add[2 * v] += add[v];
		add[2 * v + 1] += add[v];
	}
	add[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int x)
{
	if (tl > r || tr < l) return;
	push(v, tl, tr);
	if (tl >= l && tr <= r) 
	{
		add[v] += x;
		push(v, tl, tr);
		return;
	}
	int mid = (tl + tr) / 2;
	update(2 * v, tl, mid, l, r, x);
	update(2 * v + 1, mid + 1, tr, l, r, x);
	push(2 * v, tl, mid);
	push(2 * v + 1, mid + 1, tr);
	t[v] = t[2 * v] + t[2 * v + 1];
}

ll get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	push(v, tl, tr);
	if (tl >= l && tr <= r) return t[v];
	int mid = (tl + tr) / 2;
	return get(2 * v, tl, mid, l, r) + get(2 * v + 1, mid + 1, tr, l, r);
}

void solve()
{
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	for (int i = 1, c, l, r, x; i <= m; i ++)
	{
		scanf("%d%d%d", &c, &l, &r);
		if (!c)
		{
			scanf("%d", &x);
			update(1, 1, n, l, r, x);
		}
		else printf("%lld\n", get(1, 1, n, l, r));
	}
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();	
}


