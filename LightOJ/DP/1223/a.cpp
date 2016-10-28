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

int T, dp[101][101][10], was[101][101][10], m, k;

int go (int l, int r, int x)
{
	if (l > r) return 0;
	if (x == 0) return inf;
	if (was[l][r][x] == T) return dp[l][r][x];
	was[l][r][x] = T;
	int res = inf;
	for (int i = l; i <= r; i ++)
	{
		res = min(res, max(go(l, i - 1, x - 1), go(i + 1, r, x)) + i);
	}
	return dp[l][r][x] = res;
}

void solve(int test)
{
	//T ++;
	scanf("%d%d", &k, &m);
	k = min(8, k);
	printf("Case %d: %d\n", test, go(1, m, k));
}

int test;

int main ()
{
	T=1;scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve(i);
}