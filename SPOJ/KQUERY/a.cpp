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
	node * l, * r;
	int cnt;	
	node()
	{
		l = NULL;
		r = NULL;
		cnt = 0;
	}
} t[30010];

vector <int> v;
map <int, int> id;
int n, a[30010], l[200100], r[200100], x[200100], q;

int getCnt(node * T)
{
	if (T == NULL) return 0;
	return T -> cnt;
}

void build (node * T, int tl, int tr)
{
	if (tl == tr) T -> cnt = 0;
	else
	{
		T -> l = new node();
		T -> r = new node();
		int mid = (tl + tr) / 2;
		build(T -> l, tl, mid);
		build(T -> r, mid + 1, tr);
		T -> cnt = 0;
	}
}

void update(node * A, node * B, int tl, int tr, int pos, int x)
{
	if (tl == tr) B -> cnt = getCnt(A) + x;
	else
	{
		int mid = (tl + tr) / 2;
		if (pos <= mid)
		{
			B -> r = A -> r;
			B -> l = new node();
			update(A -> l, B -> l, tl, mid, pos, x); 
		}
		else
		{
			B -> l = A -> l;
			B -> r = new node();
			update(A -> r, B -> r, mid + 1, tr, pos, x);
		}
		B -> cnt = getCnt(B -> l) + getCnt(B -> r);
	}
}

int get(node * A, node * B, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return getCnt(B) - getCnt(A);
	int mid = (tl + tr) / 2;
	return get(A -> l, B -> l, tl, mid, l, r) + get(A -> r, B -> r, mid + 1, tr, l, r);
}

int main ()
{      
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) 
	{
		scanf("%d", a + i);
		v.pb(a[i]);
	}

	scanf("%d", &q);
	for (int i = 1; i <= q; i ++)
	{
		scanf("%d%d%d", l + i, r + i, x + i);
	}

	v.pb(inf);
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for (int i = 0; i < sz(v); i ++) id[v[i]] = i + 1;
	build(& t[0], 1, n);

	for (int i = 1; i <= n; i ++)
	{
		update(& t[i - 1], & t[i], 1, n, id[a[i]], 1);
	}
	
	for (int i = 1; i <= q; i ++)
	{
		int pos = upper_bound(all(v), x[i]) - v.begin();
		printf("%d\n", get(& t[l[i] - 1], & t[r[i]], 1, n, id[v[pos]], n));
	}

}


