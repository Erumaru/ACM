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

ll n, m, b, mb = inf, dp[1 << 12][1 << 12], ans;
string s;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> s;
	dp[0][0] = 1;
	for (int i = 1; i <= 2e3; i ++)
	{
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= i; j ++)
		{
			dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % inf;
			//cout << dp[i][j] << " ";
		}
		//cout << "\n";
	}	                            

	for (int i = 0; i < sz(s); i ++)
	{
		if (s[i] == '(') b ++;
		else b --;
		mb = min(mb, b);
	}

	for (int c = 0; c <= n - m; c ++)
	{
		for (int d = 0; d <= c; d ++)
		{
			if (d >= -mb)
			{
				if (d + b <= n - m && d + b >= 0) 
				{
					ans = (ans + dp[c][d] * dp[n - m - c][d + b]) % inf;
				}
			}
		}
	}

	cout << ans << "\n";
}


