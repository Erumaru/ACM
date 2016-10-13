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

int n, m;
int a[120010], b[120010];
vector <int> t[120100];
map <int, int> last;

void build (int v, int tl, int tr)
{
	if (tl == tr) t[v].pb(b[tl]);
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		merge(all(t[2 * v]), all(t[2 * v + 1]), back_inserter(t[v]));
	}
}

int get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r)
	{
		int h = upper_bound(all(t[v]), r) - t[v].begin();
		return sz(t[v]) - h;
	}
	int mid = (tl + tr) / 2;
	return get(2 * v, tl, mid, l, r) + get(2 * v + 1, mid + 1, tr, l, r);
}

int main ()
{      
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	for (int i = n; i > 0; i --)
	{
		if (!last.count(a[i])) b[i] = inf;
		else b[i] = last[a[i]];
		last[a[i]] = i;
	}	

	build (1, 1, n);
	scanf("%d", &m);
	for (int i = 1, l, r; i <= m; i ++)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", get(1, 1, n, l, r));
	}
}


