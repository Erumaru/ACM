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

int s[200100], suff[200100], nsuff[200100], col[200100], ncol[200100], head[200100], n, k, sz, 
	ind[200100], p[200100], lcp[200100], two[200100], tab[20][200100], width[200100], w[200100],
	last[200100], b[200100];
char tmp[100100];
ll ans[100100];
vector <int> t[1000100];

int cmp(int i, int j)
{
	return s[i] < s[j];
}

void calc()
{
	n = sz;
	for(int i = 0; i < n; i ++) suff[i] = i;
	sort(suff, suff + n, cmp);

	int cn = 0;
	for (int i = 0; i < n; i ++)
	{
		if (i == 0 || s[suff[i]] != s[suff[i - 1]])
		{
			col[suff[i]] = cn;
			head[cn] = i;
			cn ++;
		}
		else col[suff[i]] = cn - 1;
	}

	for (int len = 1; len <= n; len *= 2)
	{
		for (int i = 0; i < n; i ++)
		{
			int pos = suff[i] - len;
			if (pos < 0) pos += n;
			nsuff[head[col[pos]]] = pos;
			head[col[pos]] ++;
		}

		for (int i = 0; i < n; i ++) suff[i] = nsuff[i];
		cn = 0;

		for (int i = 0; i < n; i ++)
		{
			if (i == 0 || col[suff[i]] != col[suff[i - 1]] ||
				col[(suff[i] + len) % n] != col[(suff[i - 1] + len) % n])
			{
				ncol[suff[i]] = cn;
				head[cn] = i;
				cn ++;
			}
			else ncol[suff[i]] = cn - 1;
		}

		for (int i = 0; i < n; i ++) col[i] = ncol[i];
	}

	/*
	for (int i = 0; i < n; i ++)
	{
		for (int j = suff[i]; j < n; j ++) 
		{
			if (s[j] > 0) printf("%c", char(s[j]));
			else printf("(%d)", s[j]);
		}
		puts("");
	}
	*/

	for (int i = 0; i < n; i ++) p[suff[i]] = i;

	int len = 0;
	for (int i = 0; i < n; i ++)
	{
		int pos = p[i];
		if (pos == n - 1)
		{
			len = 0;
			lcp[pos] = 0;
			continue;
		}
		len = max(len - 1, 0);
		while (i + len < n && suff[pos + 1] + len < n &&
			s[suff[pos] + len] == s[suff[pos + 1] + len]) len ++;
		lcp[pos] = len;
	}

	//for (int i = 0; i < n; i ++) printf("%d ", lcp[i]);
}

void sparse()
{
	two[0] = -1;
	for (int i = 1; i <= n; i ++)
	{
		two[i] = two[i / 2] + 1;
		tab[0][i] = lcp[i];
	}

	for (int i = 1; (1 << i) <= n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			tab[i][j] = min(tab[i - 1][j], tab[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int get(int l, int r)
{
	assert(r >= l);
	int lvl = two[r - l + 1];
	return min(tab[lvl][l], tab[lvl][r - (1 << lvl) + 1]);
}

int getString (int x)
{
	return ind[x];
}

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

int getUnique(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r)
	{
		int res = upper_bound(all(t[v]), r) - t[v].begin();
		res = sz(t[v]) - res;
		return res;
	}
	int mid = (tl + tr) / 2;
	return getUnique(2 * v, tl, mid, l, r) + getUnique(2 * v + 1, mid + 1, tr, l, r);
}

int main ()
{      
	scanf("%d%d", &n, &k);
	int pp = -1;
	int nn = n;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", tmp);
		int len = strlen(tmp);
		for (int j = 0; j < len; j ++) 
		{
			s[sz ++] = tmp[j];
			ind[sz - 1] = i;
			width[sz - 1] = len - j;
		}
		s[sz ++] = pp --;
		ind[sz - 1] = inf;
	}

	calc();
	sparse();
	for (int i = 0; i < n; i ++)
	{
		w[i] = getString(suff[i]);
	}

	for (int i = 1; i <= nn; i ++) last[i] = inf;
	for (int i = n - 1; i >= 0; i --)
	{
		if (w[i] == inf)
		{
			b[i] = -inf;
			continue;
		}
		b[i] = last[w[i]];
		last[w[i]] = i;
	}

	build(1, 0, n - 1);

	for (int i = 0; i < n; i ++)
	{
		if (s[i] < 0) continue;
		int cur = getString(i), pos = p[i];
		int l = 0, r = width[i];
		int curans;
		//cout << i << " " << cur << " + " << pos << " " << l << " " << r << "\n";
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int bot = pos, top = pos;
			if (lcp[pos - 1] < mid) top = pos;
			else 
			{
				int tl = 0, tr = pos - 1;
				while (tl <= tr)
				{
					int tmid = (tl + tr) / 2;
					//cerr << tmid << " " << tl << " " << tr << "\n";
					if (get(tmid, pos - 1) >= mid) top = tmid, tr = tmid - 1;
					else tl = tmid + 1;
				}
			}
			if (lcp[pos] < mid) bot = pos;
			else
			{
				int tl = pos + 1, tr = n - 1;
				while (tl <= tr)
				{
					int tmid = (tl + tr) / 2;
					//cout << tmid << " ";
					if (get(pos, tmid - 1) >= mid) bot = tmid, tl = tmid + 1;
					else tr = tmid - 1;
				}
			}

			//cout << bot << " - " << top << " " << mid << "\n";
			if (getUnique(1, 0, n - 1, top, bot) >= k) curans = mid, l = mid + 1;
			else r = mid - 1;
		}

		//cout << curans << "\n";
		ans[cur] += curans;
	}

	for (int i = 1; i <= nn; i ++) printf("%lld ", ans[i]);
}


