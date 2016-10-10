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

int n, q, s[400100], sz, suff[400100], nsuff[400100], ncol[400100], col[400100], head[400100],
	lcp[400100], p[400100], id[400100], tab[30][400100], len[400100], w[400100], nw[400100], two[400100];
char t[400100];

vector <int> tt[2000100];
vector <int> pr[2000100];

bool cmp(int i, int j)
{
	return s[i] < s[j];
}

void myMerge(vector <int> &ans, vector <int> &l, vector <int> &r, vector <int> &pr)
{
	l.pb(inf);
	r.pb(inf);
	int i = 0, j = 0, cnt = 0;
	int t = 0;
	while (i < sz(l) && j < sz(r))
	{
		if (l[i] == inf && r[j] == inf) return;
		if (l[i] < r[j]) ans.pb(l[i]), i ++;
		else ans.pb(r[j]), j ++, cnt ++;
		pr.pb(cnt);
	}
}

void suffix_array()
{
	n = sz;
	for (int i = 0; i < n; i ++) suff[i] = i;
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
}

void build (int v, int tl, int tr)
{
	if (tl == tr) 
	{
		tt[v].pb(nw[tl]);
	}
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		myMerge(tt[v], tt[2 * v], tt[2 * v + 1], pr[v]);
	}
}

void sparse()
{
	two[0] = -1;
	tab[0][0] =  lcp[0];
	for (int i = 1; i < n; i ++)
	{
		two[i] = two[i / 2] + 1;
		tab[0][i] = lcp[i];
	}
	two[n] = two[n / 2] + 1;

	for (int i = 1; (1 << i) <= n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			tab[i][j] = min(tab[i - 1][j], tab[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int getMin(int l, int r)
{
	assert(l <= r);
	int lvl = two[r - l + 1];
	return min(tab[lvl][l], tab[lvl][r - (1 << lvl) + 1]);
}

int get(int v, int tl, int tr, int l, int r, int bot, int top)
{
	if (tl > r || tr < l) return 0;
	if (v == 1)
	{
		bot = lower_bound(all(tt[v]), bot) - tt[v].begin();
		top = upper_bound(all(tt[v]), top) - tt[v].begin();
	}
	if (tl >= l && tr <= r)
	{
		//cout << bot << " " << top << "\n";
		return max(0, top - bot);
	}
	int mid = (tl + tr) / 2;
	int botForL = bot, botForR = bot;
	if (bot > 0) botForL = bot - pr[v][bot - 1], botForR = pr[v][bot - 1];
	int topForL = top, topForR = top;
	if (top > 0) topForL = top - pr[v][top - 1], topForR = pr[v][top - 1];
	return get(2 * v, tl, mid, l, r, botForL, topForL) + 
		get(2 * v + 1, mid + 1, tr, l, r, botForR, topForR);
}

int getString(int x)
{
	return w[x];
}

int main ()
{      
	scanf("%d%d", &n, &q);
	int pp = -1;
	for (int i = 0; i < n; i ++)
	{
		scanf("%s", t);
		int tmp = strlen(t);
		id[i + 1] = sz;
		len[i + 1] = tmp;
		for (int j = 0; j < tmp; j ++) s[sz ++] = t[j], w[sz - 1] = i + 1;	
		s[sz ++] = pp;
		pp --;
	}	
	suffix_array();
	for (int i = 0; i < n; i ++) 
	{
		int pos = suff[i];
		pos = getString(pos);
		nw[i] = pos;
	}
	build(1, 0, sz - 1);
	sparse();

	for (int i = 0, l, r, k; i < q; i ++)
	{
		scanf("%d%d%d", &l, &r, &k);
		int pos = id[k];
		//cout << "\n + " <<  pos << " ";
		pos = p[pos];
		//cout << pos << " + \n";
		int nlcp = len[k];
		int top, bot;
		//for (int i = 0; i < sz; i ++) cout << i << ": " << lcp[i] << "\n";

		//cout << nlcp << " " << pos << "\n";
		if (lcp[pos - 1] < nlcp) top = pos;
		else
		{
			int l = 0, r = pos - 1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				int query = getMin(mid, pos-1);
				if (query >= nlcp) r = mid - 1, top = mid;
				else l = mid + 1;
			}
		}

		if (lcp[pos] < nlcp) bot = pos;
		else
		{
			int l = pos+1, r = sz - 1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				int query = getMin(pos, mid-1);
				//cout << mid << " + " << query << "\n";
 				if (query >= nlcp) l = mid + 1, bot = mid;
				else r = mid - 1;
			}
		}

		//cout << top << " " << bot + 1<< " " << l << " " << r << " " << k << "\n";
		//if (bot + 1 - top >= 0)
		//{
			printf("%d\n", get(1, 0, sz - 1, top, bot, l, r));
		//}
		//else printf("0\n");
	}
}


