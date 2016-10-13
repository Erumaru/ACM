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

int dp[101][501], n, balance, a[101], b[101], cost[101][501];

int go(int x, int y)
{
	if (y > balance) return -inf;
	if (x == n) 
	{
		cost[x][y] = y;
		return 0;
	}
	if (dp[x][y] != -1) return dp[x][y];
	x ++;
	//return dp[x - 1][y] = max(go(x, y + a[x]) + b[x], go(x, y));
	int take = go(x, y + a[x]) + b[x], dont = go(x, y);
	if (dp[x - 1][y] < take)
	{
		dp[x - 1][y] = take;
		cost[x - 1][y] = cost[x][y + a[x]];
	}
	else if (dp[x - 1][y] == take)
	{
		if (cost[x - 1][y] == - 1 || cost[x - 1][y] > cost[x][y + a[x]]) cost[x - 1][y] = cost[x][y + a[x]];
	}
	if (dp[x - 1][y] < dont)
	{
		dp[x - 1][y] = dont;
		cost[x - 1][y] = cost[x][y];
	}
	else if (dp[x - 1][y] == dont)
	{
		if (cost[x - 1][y] == -1 || cost[x - 1][y] > cost[x][y]) cost[x - 1][y] = cost[x][y];
	}

	return dp[x - 1][y];
}


int main ()
{      
	while (~scanf("%d%d", &balance, &n))	
	{
		if (balance == 0 && n == 0) return 0;

		for (int i = 0; i <= n; i ++)
		{
			for (int j = 0; j <= balance; j ++)
			{
				dp[i][j] = -1;
				cost[i][j] = -1;
			}
		}

		for (int i = 1; i <= n; i ++) scanf("%d%d", a + i, b + i);

		int ans = max(0, go(0, 0));	
		printf("%d %d\n", cost[0][0], ans);	
	}	
}


