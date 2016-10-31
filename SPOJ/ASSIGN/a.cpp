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

int p[25][25], d[25], n, T, was[1100100];
ll dp[1100100];

ll go (int mask)
{
	if (mask == (1 << n) - 1) return 1;
	if (was[mask] == T) return dp[mask];
	was[mask] = T;
	int x = __builtin_popcount(mask);
	ll res = 0;
	for (int i = 0; i < n; i ++)
	{
		if (!p[x][i]) continue;
		if (mask & (1 << i)) continue;
		res += go(mask | (1 << i));
	}
	return dp[mask] = res;
}

void solve()
{
	T ++;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
	{
		d[i] = 0;
		for (int j = 0; j < n; j ++)
		{
			scanf("%d", &p[i][j]);
			d[i] |= (p[i][j] << j);
		}
	}

	printf("%lld\n", go(0));
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();
}


