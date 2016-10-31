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

int T, n, k, p[110], dp[110][110], was[110][110];

int go (int x, int y)
{
	if (x == k)
	{
		return 0;
	}
	if (was[x][y] == T) return dp[x][y];
	was[x][y] = T;

	int res = inf;
	for (int i = 1; i <= k; i ++) 
	{
		if (x + i > k) break;
		if (p[i] == -1) continue; 
		res = min(res, go(x + i, y + 1) + p[i]);
	}
	return dp[x][y] = res;
}

void solve()
{
	T ++;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i ++) scanf("%d", &p[i]);
	int ans = go(0, 0);
	if (ans == inf) ans = -1;
	printf("%d\n", ans);
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();
}


