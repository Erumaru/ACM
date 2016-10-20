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

int n, a[200100], l[100100], r[100100], st[200100], p;

int main ()
{      
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i], a[n + i] = a[i];

	for (int i = 1; i <= 2 * n; i ++)
	{
		int pos = i - n;
		if (pos <= 0) pos += n;
		//cout << i << ": " << pos << "\n";
		while (p > 0 && a[st[p - 1]] >= a[pos]) p --;
		if (p == 0) l[pos] = inf;
		else l[pos] = st[p - 1];
		st[p ++] = pos;
	}	

	p = 0;
	for (int i = 2 * n; i > 0; i --)
	{
		int pos = i - n;
		if (pos <= 0) pos += n;
		while (p > 0 && a[st[p - 1]] >= a[pos]) p --;
		if (p == 0) r[pos] = inf;
		else r[pos] = st[p - 1];
		st[p ++] = pos;
	}	

	int ans = inf, x1, x2, x3;
	for (int i = 1; i <= n; i ++)
	{
		int cur = 0;
		if (l[i] == inf || r[i] == inf) continue;
		if (l[i] < i) cur += i - l[i];
		else cur += n - (l[i] - i);
		if (r[i] > i) cur += r[i] - i;
		else cur += n - (i - r[i]);

		if (cur < ans)
		{
			ans = cur;
			x1 = l[i];
			x2 = i;
			x3 = r[i];
		}
	}

	cout << x1 << " " << x2 << " " << x3 << "\n";
}


