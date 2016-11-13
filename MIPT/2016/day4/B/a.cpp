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

using namespace std;

#define F first
#define S second
#define sz(a) int((a).size())
#define all(a) (a).begin, (a).end
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

const int inf = 1e9;
const int mod = 1e9 + 7;
const int maxn = 1e6;
const ll INF = 1e18;

char s[5010];
int suff[5010], col[5010], nsuff[5010], ncol[5010], head[5010], n, lcp[5010], p[5010];

bool cmp(int i, int j)
{
	return s[i] < s[j];
}

void suff_array()
{
	s[n] = '#';
	n ++;

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
	for (int i = 0; i < n; i ++) suff[i] = suff[i + 1];
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
		len = max(0, len - 1);
		while (i + len < n && suff[pos + 1] + len < n && s[suff[pos] + len] == s[suff[pos + 1] + len]) len ++;
		lcp[pos] = len;
	}
}

int get(int l, int r)
{
	int res = 0;

	for (int i = 1; i < n; i ++)
	{
			
	}

	return res;
}

int main () 
{
	scanf("%s", s);
	n = strlen(s);
	int q;
	scanf("%d", &q);
	suff_array();
	for (int i = 1, l, r; i <= q; i ++)
	{
		scanf("%d%d", &l, &r);
		l --;
		r --;
		printf("%d\n", get(l, r));
	}
}