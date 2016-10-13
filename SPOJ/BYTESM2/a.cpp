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

int h, w, a[110][110], dp[110][110];

void solve()
{
	scanf("%d %d", &h, &w);
	for (int i = 1; i <= h; i ++)
	{
		for (int j = 1; j <= w; j ++)
		{
			scanf("%d", &a[i][j]);
		}
	}	

	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= h; i ++)
	{
		for (int j = 1; j <= w; j ++)
		{
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][max(1, j - 1)]);
			dp[i][j] = max(dp[i][j], dp[i - 1][min(w, j + 1)]);
			dp[i][j] += a[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= w; i ++) ans = max(ans, dp[h][i]);
	printf("%d\n", ans);
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();	
}


