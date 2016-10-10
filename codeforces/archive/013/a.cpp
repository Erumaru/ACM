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

ll n, a[100100], b[100100], pos[100100], ans, ans2;
vector <int> g[5], v;
pii p[100100];
map <int, int> id;
int t[800100][5];

bool cmp (int i, int j)
{
	return p[i] < p[j];
}

void update(int v, int tl, int tr, int pos, int x, int tree)
{
	if (tl == tr) t[v][tree] += x;
	else
	{
		int mid = (tl + tr) / 2;
		if (pos <= mid) update(2 * v, tl, mid, pos, x, tree);
		else update(2 * v + 1, mid + 1, tr, pos, x, tree);
		t[v][tree] = t[2 * v][tree] + t[2 * v + 1][tree];
 	}
}

int get(int v, int tl, int tr, int l, int r, int tree)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return t[v][tree];
	int mid = (tl + tr) / 2;
	return get(2 * v, tl, mid, l, r, tree) + get(2 * v + 1, mid + 1, tr, l, r, tree);
}

int main ()
{      
	freopen("john.in", "r", stdin);
	freopen("john.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d", a + i, b + i);
		p[i] = mp(a[i], b[i]);
	}
	sort(p + 1, p + 1 + n);

	for (int i = 1; i <= n; i ++) v.pb(a[i]), v.pb(b[i]);
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());

	for (int i = 0; i < sz(v); i ++) id[v[i]] = i + 1;
	
	for (int i = 1; i <= n; i ++)
	{
		//cout << a[pos[i]] << " " << b[pos[i]]<< "\n";// << p[i] << "\n";
		ans += get(1, 1, 2 * n, id[p[i].ft] + 1, 2 * n, 1);
		ans += get(1, 1, 2 * n, id[p[i].st] + 1, 2 * n, 2);
		update(1, 1, 2 * n, id[p[i].ft], 1, 1);
		update(1, 1, 2 * n, id[p[i].st], 1, 2);
	}

	memset(t, 0, sizeof t);

	for (int i = 1; i <= n; i ++) p[i] = mp(b[i], a[i]);
	sort(p + 1, p + 1 + n);

	for (int i = 1; i <= n; i ++)
	{
		ans2 += get(1, 1, 2 * n, id[p[i].ft] + 1, 2 * n, 1);
		ans2 += get(1, 1, 2 * n, id[p[i].st] + 1, 2 * n, 2);
		update(1, 1, 2 * n, id[p[i].ft], 1, 1);
		update(1, 1, 2 * n, id[p[i].st], 1, 2);
	}

	printf("%lld\n", min(ans, ans2));
}


