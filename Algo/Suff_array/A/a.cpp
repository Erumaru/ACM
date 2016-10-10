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

string s;
int l, r, lcp[10010], col[10010], head[10010], suff[10010], nsuff[10010], ncol[10010], p[10010], ln[10010];

bool cmp(int i, int j)
{
	return s[i] < s[j];
}

void solve(int test)
{
	cin >> s >> l >> r;
	s += "#";
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

	n --;
	s.erase(n);

	for (int i = 0; i < n; i ++) suff[i] = suff[i + 1];
	for (int i = 0; i < n; i ++)
	{
		p[suff[i]] = i;
	}

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
		while (i + len < n && suff[pos + 1] + len < n && s[suff[pos]] == s[suff[pos + 1]]
			&& s[suff[pos] + len] == s[suff[pos + 1] + len]) len ++;
		lcp[pos] = len;
	}

	int ans = 0;

	for (int i = 0; i < n; i ++) ln[i] = sz(s) - suff[i];
	
	ans += max(0, min(r, ln[0]) - l + 1);

	for (int i = 1; i < n; i ++)
	{
		int L = max(l, lcp[i - 1] + 1), R = min(r, ln[i]);
		ans += max(0, R - L + 1);
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


