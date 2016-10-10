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

int n, dp[100010][5][5];
char s[100010];

int main ()
{      
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i ++)
	{
		dp[i][0][0] = dp[i - 1][0][0];
		dp[i][0][1] = dp[i - 1][0][1];

		if (s[i] == '0') dp[i][0][0] = max(dp[i][0][0], dp[i - 1][0][1] + 1);
		else dp[i][0][1] = max(dp[i][0][1], dp[i - 1][0][0] + 1);

		dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
		dp[i][1][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);

		if (s[i] == '0') 
		{
			dp[i][1][1] = max(dp[i][1][1], dp[i - 1][0][0] + 1);
			dp[i][1][1] = max(dp[i][1][1], dp[i - 1][1][0] + 1);
		}
		else
		{
			dp[i][1][0] = max(dp[i][1][0], dp[i - 1][0][1] + 1);
			dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][1] + 1);
		}

		dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][1][1]);
		dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0]);

		if (s[i] == '0')
		{
			dp[i][2][0] = max(dp[i][2][0], dp[i - 1][2][1] + 1);
			dp[i][2][0] = max(dp[i][2][0], dp[i - 1][1][1] + 1);
		}
		else
		{
			dp[i][2][1] = max(dp[i][2][1], dp[i - 1][2][0] + 1);
			dp[i][2][1] = max(dp[i][2][1], dp[i - 1][1][0] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < 3; i ++)
	{
		for (int j = 0; j < 2; j ++)
		{
			ans = max(ans, dp[n][i][j]);
		}
	}

	/*for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < 3; j ++)
		{
			for (int k = 0; k < 2; k ++)
			{
				printf("%d ", dp[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}*/

	printf("%d", ans);
}


