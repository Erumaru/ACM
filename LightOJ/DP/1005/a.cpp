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

int n, k;
ll dp[40][40][40];

ll go (int l, int r, int x)
{
	if (l == 0) 
	{
		if (x == 0) return 1;
		return 0;
	}
	if (dp[l][r][x] !=-1) return dp[l][r][x];
	return dp[l][r][x] = go(l - 1, r - 1, x - 1) * r + go(l - 1, r, x);
}

void solve(int test)
{
	scanf("%d%d", &n, &k);

	ll ans = 0;
	if (k <= n)
	{
		ans = go(n, n, k);
	}
	printf("Case %d: %lld\n", test, ans);
}

int test;

int main ()
{      
	memset(dp, -1, sizeof dp);
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve(i);	
}


