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

int n, was[17][70010], dp[17][70010], a[17][17], T;

int go (int x, int mask)
{
	if (was[x][mask] == T) return dp[x][mask];
	was[x][mask] = T;
	if (x >= n) return dp[x][mask] = 0;

	int res = 0;
	for (int i = 0; i < n; i ++)
	{
		if (mask & (1 << i)) continue;
		res = max(res, go(x + 1, mask | (1 << i)) + a[x][i]);
	}
	return dp[x][mask] = res;
}

void solve(int test)
{
	T ++;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("Case %d: %d\n", test, go(0, 0));
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve(i);	
}


