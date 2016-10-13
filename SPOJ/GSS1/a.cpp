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

struct node
{
	ll sum, pref, suff, ans;
	node(){}
	node(ll sum, ll pref, ll suff, ll ans) : sum(sum), pref(pref), suff(suff), ans(ans) {}
} t[200010];

int n, m, a[50010];

node make(int val)
{
	return node(val, val, val, val);
}

node merge(node l, node r)
{
	return node(l.sum + r.sum, max(l.pref, l.sum + r.pref), 
		max(r.suff, r.sum + l.suff), max(max(l.ans, r.ans), l.suff + r.pref));
}

void build (int v, int tl, int tr)
{
	if (tl == tr) t[v] = make(a[tl]);
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		t[v] = merge(t[2 * v], t[2 * v + 1]);
	}
}

node get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return node(-inf, -inf, -inf, -inf);
	if (tl >= l && tr <= r) return t[v];
	int mid = (tl + tr) / 2;
	return merge(get(2 * v, tl, mid, l, r), get(2 * v + 1, mid + 1, tr, l, r)); 
}

int main ()
{      
	scanf("%d", &n);	
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	build(1, 1, n);
	scanf("%d", &m);
	for (int i = 1, l, r; i <= m; i ++)
	{
		scanf("%d%d", &l, &r);
		printf("%lld\n", get(1, 1, n, l, r).ans);
	}
}


