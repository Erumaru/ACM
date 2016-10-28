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

int n, dp[210][110], a[210][110];

void solve(int test)
{
	scanf("%d", &n);
	for (int i = 0; i <= 200; i ++)
	{
		for (int j = 0; j <= 105; j ++) dp[i][j] = 0;
	}
	int x = 1;
	for (int i = 1; i <= 2 * n - 1; i ++)
	{
		for (int j = 1; j <= x; j ++)
		{
			scanf("%d", &a[i][j]);
 		}
		if (i < n) x ++;
		else x --; 
	}

	x = 1;
	for (int i = 1; i <= 2 * n - 1; i ++)
	{
		if (i <= n)
		{
			for (int j = 1; j <= x; j ++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
			}
		}
		else
		{
			for (int j = 1; j <= x; j ++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + a[i][j];
			}
		}
		if (i < n) x ++;
		else x --;
	}
	printf("Case %d: %d\n", test, dp[2 * n - 1][1]);
}

int test;

int main ()
{     
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve(i);
}


