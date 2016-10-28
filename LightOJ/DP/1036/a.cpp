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

int n, m, a[510][510], b[510][510], was[510][510], T;
ll dp[510][510];

ll go (int row, int pos)
{
	if (was[row][pos] == T) return dp[row][pos];
	was[row][pos] = T;
	if (row == n) return dp[row][pos] = 0;
	ll res = 0;
	for (int i = pos; i <= m; i ++)
	{
		res = max(res, go(row + 1, i) + a[row + 1][i] + b[row + 1][i + 1]);
	}
	return dp[row][pos] = res;
}

void solve(int test)
{
	T ++;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			scanf("%d", &a[i][j]);
			a[i][j] += a[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		b[i][m + 1] = 0;
		for (int j = m; j > 0; j --)
		{
			b[i][j] += b[i][j + 1];
		}
	}

	ll ans = go(0, 0);

	printf("Case %d: %lld\n", test, ans);
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve(i);	
}


