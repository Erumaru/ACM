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

char s[100100];
int suff[100100], nsuff[100100], col[100100], ncol[100100], head[100100], n,
	p[100100], lcp[100100], table[17][100100], len[100100], two[100100], ans, 
	num[100100], K;

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
} t[100100];

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
		build (T -> l, tl, mid);
		build (T -> r, mid + 1, tr);
		T -> cnt = getCnt(T -> l) + getCnt(T -> r);
	}
}

void update(node * P, node * T, int tl, int tr, int pos)
{
	if (tl == tr) T -> cnt = 1;
	else
	{
		int mid = (tl + tr) / 2;
		if (pos <= mid)
		{
			T -> r = P -> r;
			T -> l = new node();
			update(P -> l, T -> l, tl, mid, pos);
		}
		else
		{
			T -> l = P -> l;
			T -> r = new node();
			update(P -> r, T -> r, mid + 1, tr, pos);
		}
		T -> cnt = getCnt(T -> l) + getCnt(T -> r);
	}
}

int getK(node * A, node * B, int tl, int tr, int k)
{
	if (tl == tr) 
	{
		if (getCnt(B) - getCnt(A) != k) return -1;
		return tl;
	}
	else
	{
		int mid = (tl + tr) / 2;
		int cur = getCnt(B -> l) - getCnt(A -> l);
		if (cur >= k) return getK(A -> l, B -> l, tl, mid, k);
		return getK(A -> r, B -> r, mid + 1, tr, k - cur);
	}
}

int getSum(node * A, node * B, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return getCnt(B) - getCnt(A);
	int mid = (tl + tr) / 2;
	return getSum(A -> l, B -> l, tl, mid, l, r) + getSum(A -> r, B -> r, mid + 1, tr, l, r);
}

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

	for (int len = 1; len <= n; len += len)
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
		len = max(len - 1, 0);
		while (i + len < n && suff[pos + 1] + len < n &&
			s[suff[pos] + len] == s[suff[pos + 1] + len]) len ++;
		lcp[pos] = len;
	}
}

int getMin(int l, int r)
{
	int lvl = two[r - l + 1];
	return min(table[lvl][l], table[lvl][r - (1 << lvl) + 1]);
}

bool ok(int x, int cur)
{
	int top = cur, bot = cur;
	if (cur < n)
	{
		if (lcp[cur] < x) bot = cur;
		else
		{
			int l = cur + 1, r = n - 1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (getMin(cur, mid - 1) >= x) bot = mid, l = mid + 1;
				else r = mid - 1;
			}
		}
	}

	int cnt = 0;	
	int prev = -1;
	while (cnt < K)
	{
		int k = getSum(& t[top], & t[bot + 1], 0, n - 1, 0, prev);
		int g = getK(& t[top], & t[bot + 1], 0, n - 1, k + 1);
		if (g == -1) break;
		cnt ++;
		prev = g + x;
		if (x != 0) prev --;
	}

	return cnt == K;
}


void sparse_table()
{
	two[0] = -1;
	for (int i = 1; i <= n; i ++) two[i] = 1 + two[i / 2];
	for (int i = 0; i < n; i ++) table[0][i] = lcp[i]; 

	for (int i = 1; (1 << i) <= n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
		}
	}
}

int main ()
{      
	scanf("%d", &K);
	scanf("%s", s);
	n = strlen(s);
	suff_array();
	sparse_table();	
	build(& t[0], 0, n - 1);
	for (int i = 0; i < n; i ++) update(& t[i], & t[i + 1], 0, n - 1, suff[i]);

	for (int i = 0; i < n; i ++) len[i] = n - suff[i];

	for (int i = 0; i < n; i ++)
	{
		int added = 0;
		if (i) added = min(num[i - 1], lcp[i - 1]);
		
		int l = added, r = len[i], cur = added;
		for (int j = l; j <= r; j ++)
		{
			if (ok(j, i)) cur = j;
			else break;
		}
		/*while (l <= r)
		{
			int mid = (l + r) / 2;
			if (ok(mid, i)) cur = mid, l = mid + 1;
			else r = mid - 1;
		}*/
		ans += cur - added;
		num[i] = max(cur, added);
	}

	cout << ans << "\n";
}


