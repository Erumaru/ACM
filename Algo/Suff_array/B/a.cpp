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

string s, tt[5];
int lcp[20010], suff[20010], nsuff[20010], col[20010], 
	ncol[20010], head[20010], p[20010], t[80010], cnt[20], cnn[200010];


void build (int v, int tl, int tr)
{
	if (tl == tr) t[v] = lcp[tl];
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		t[v] = min(t[2 * v], t[2 * v + 1]);
	}
}

int get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return inf;
	if (tl >= l && tr <= r) return t[v];
	int mid = (tl + tr) / 2;
	return min(get(2 * v, tl, mid, l, r), get(2 * v + 1, mid + 1, tr, l, r));
}

bool cmp(int i, int j)
{
	return s[i] < s[j];
}

int get(int x)
{
	x = suff[x];
	if (x < sz(tt[0])) return 0;
	if (x < sz(tt[0]) + sz(tt[1]) + 1) return 1;
	return 2;
}

void calc()
{
	int n = sz(s);
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
			if (i == 0 || col[suff[i]] != col[suff[i - 1]] 
				|| col[(suff[i] + len) % n] != col[(suff[i - 1] + len) % n])
			{
				ncol[suff[i]] = cn;
				head[cn] = i;
				cn ++;
			}
			else ncol[suff[i]] = cn - 1;
		}

		for (int i = 0; i < n; i ++) col[i] = ncol[i];
	}

	//n -= 3;
	//s.erase(sz(tt[0]), 1);
	//s.erase(sz(tt[0]) + sz(tt[1]), 1);
	//s.erase(sz(s) - 1);

	//for (int i = 0; i < n; i ++) suff[i] = suff[i + 3];

	for (int i = 0; i < n; i ++) p[suff[i]] = i;

	int len = 0;
	for (int i = 0; i < n; i ++)
	{
		int pos = p[i];
		if (pos == n - 1)
		{
			lcp[pos] = 0;
			len = 0;
			continue;
		}
		len = max(len - 1, 0);
		while (i + len < n && suff[pos + 1] + len < n && 
			s[suff[pos] + len] == s[suff[pos + 1] + len]) len ++;
		lcp[pos] = len;
	}

	/*for (int i = 0; i < n; i ++)
	{
		cout << get(i) << ": ";
		for (int j = suff[i]; j < n; j ++) cout << s[j];
			cout << "\n";
	}*/
	//for (int i = 0; i < n; i ++) cout << lcp[i] << " ";
	//n -= 3;
	//for (int i = 0; i < n; i ++) lcp[i] = lcp[i + 3];
	//cout << "\n";
}

bool check()
{
	for (int i = 0; i < 3; i ++) if (!cnt[i]) return false;
	return true;
}


void solve(int test)
{
	for (int i = 0; i < 3; i ++) cin >> tt[i];
	s = tt[0] + "#" + tt[1] + "$" + tt[2] + "!";
	calc();
	int n = sz(s);
	build (1, 0, n - 2);
	int l = 3;
	int ans = 0;
	for (int i = 0; i < 3; i++) cnt[i] = 0;
	for (int r = 3; r < n; r ++)
	{
		//cout << l << " " << r << "\n";
		cnt[get(r)] ++;
		while (l <= r && check())
		{
			if (l == r) {
				assert(false);
			}
			ans = max(ans, get(1, 0, n - 2, l, r - 1));
			cnt[get(l)] --;
			l ++;
		}
	}

	printf("Case %d: %d\n", test, ans);
}

int test;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);       
	cin >> test;
	for (int i = 1; i <= test; i ++) solve(i);
}


