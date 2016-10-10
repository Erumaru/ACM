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
int q, suff[90010], nsuff[90010], col[90010], ncol[90010], head[90010], lcp[90010], p[90010];

bool cmp(int i, int j)
{
	return s[i] < s[j];
}

void calc()
{
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
	n --;
	s.erase(n);

	for (int i = 0; i < n; i ++) suff[i] = suff[i + 1];
	
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
}

bool ok(int x, int k)
{
	return p[x] >= k;
}

string get(int x)
{	
	int res;
	int n = sz(s);
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (ok(mid, x)) r = mid - 1, res = mid;
		else l = mid + 1;
	}

	string ans = "";
	int cur = 0;
	if (res > 0) cur = p[res - 1];


	if (res != 0) for (int i = suff[res]; i < suff[res] + lcp[res - 1]; i ++) ans += s[i];
	int start = suff[res];
	if (res > 0) start += lcp[res - 1];
	for (int i = start; i < n; i ++)
	{
		if (cur == x) break;
		cur ++;
		ans += s[i];
	}
	return ans;
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        

	cin >> s;
	cin >> q;
	calc();

	int n = sz(s);
	p[0] = n - suff[0];
	for (int i = 1; i < n; i ++) p[i] = p[i - 1] + n - (suff[i] + lcp[i - 1]);
	

	for (int i = 1, k; i <= q; i ++) 
	{
		cin >> k;
		cout << get(k) << "\n";
	}
}


