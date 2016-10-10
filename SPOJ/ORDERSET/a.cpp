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

int t[800100], a[200100], q;
char c[200100];
vector <int> v;
map <int, int> id;

void update(int v, int tl, int tr, int pos, int x)
{
	if (tl == tr) t[v] = x;
	else
	{
		int mid = (tl + tr) / 2;
		if (pos <= mid) update(2 * v, tl, mid, pos, x);
		else update(2 * v + 1, mid + 1, tr, pos, x);
		t[v] = t[2 * v] + t[2 * v + 1];
	}
}

int kth(int v, int tl, int tr, int k)
{
	if (tl == tr) return tl;
	else
	{
		int mid = (tl + tr) / 2;
		if (t[2 * v] >= k) return kth(2 * v, tl, mid, k);
		return kth(2 * v + 1, mid + 1, tr, k - t[2 * v]);
	}
}


int get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return t[v];
	int mid = (tl + tr) / 2;
	return get(2 * v, tl, mid, l, r) + get(2 * v + 1, mid + 1, tr, l, r);
}

int main ()
{      
	cin >> q;
	for (int i = 1; i <= q; i ++)
	{
		cin >> c[i] >> a[i];
		v.pb(a[i]);
	}

	sort(all(v));
	v.resize(unique(all(v)) - v.begin());

	for (int i = 0; i < sz(v); i ++) id[v[i]] = i + 1;

	int n = sz(v);
	for (int i = 1; i <= q; i ++)
	{
		if (c[i] == 'I') update(1, 1, n, id[a[i]], 1);
		else if (c[i] == 'D') update(1, 1, n, id[a[i]], 0);
		else if (c[i] == 'K') 
		{
			if (a[i] > t[1]) printf("invalid\n");
			else printf("%d\n", v[kth(1, 1, n, a[i]) - 1]);
		}
		else 
		{
			printf("%d\n", get(1, 1, n, 1, id[a[i]] - 1));
		}
	}
}


