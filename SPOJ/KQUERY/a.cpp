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

int n, a[30010], k;
vector <int> t[120010];
vector <int> pr[120010];



void build (int v, int tl, int tr)
{
	if (tl == tr) t[v].pb(a[tl]);
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		vector <pii> l = t[2 * v], r = t[2 * v + 1];
		for (int i = 0; i < sz(l); i ++) l[i].st = 0;
		for (int i = 0; i < sz(r); i ++) r[i].st = 1;
		merge(all(l), all(r), back_inserter(t[v]));	
		pr[v].resize(sz(t[v]));
		for (int i = 0; i < sz(t[v]); i ++) pr[v][i] = t[v][i].st;
		for (int i = 1; i < sz(t[v]); i ++) pr[v][i] += pr[v][i - 1]; 
	}
}

int get(int v, int tl, int tr, int l, int r, int x)
{
	if (tl > r || tr < l) return 0;
	if (v == 1)
	{
		x = upper_bound(all(t[v]), mp(x, 2)) - t[v].begin();
	} 

	if (tl >= l && tr <= r) return sz(t[v]) - x;
	int mid = (tl + tr) / 2;
	int forL = x, forR = x;
	if (x > 0) forL = x - pr[v][x - 1], forR = pr[v][x - 1];
	return get(2 * v, tl, mid, l, r, forL) + get(2 * v + 1, mid + 1, tr, l, r, forR);
}

int main ()
{      
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	build(1, 1, n);
	scanf("%d", &k);

	for (int i = 1, l, r, x; i <= k; i ++)
	{
		scanf("%d%d%d", &l, &r, &x);
		printf("%d\n", get(1, 1, n, l, r, x));
	}

}


