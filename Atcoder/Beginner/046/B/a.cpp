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

ll n, k, dp[1010][1010], ans, col[1010];

int main ()
{      
	cin >> n >> k;
	for (int i = 1; i <= k; i ++) dp[1][i] = 1;

	for (int i = 2; i <= n; i ++)
	{
		for (int j = 1; j <= k; j ++)
		{
			col[i] += dp[i - 1][j];
		}

		for (int j = 1; j <= k; j ++)
		{
			dp[i][j] = col[i] - dp[i - 1][j];
		}
	}

	for (int i = 1; i <= k; i ++) ans += dp[n][i];

	cout << ans << " ";
}


