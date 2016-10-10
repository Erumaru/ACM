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

ll n, dp[1 << 17][4], c[1 << 17];
string s[1 << 17], t[1 << 17];

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	for (int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		t[i] = s[i];
		reverse(t[i].begin(), t[i].end());
		dp[i][0] = INF;
		dp[i][1] = INF;
	}

	dp[1][1] = c[1];
	dp[1][0] = 0;
	for (int i = 2; i <= n; i ++)
	{
		if (s[i] >= s[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if (s[i] >= t[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if (t[i] >= s[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
		if (t[i] >= t[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
	}

	if (min(dp[n][0], dp[n][1]) == INF) cout << -1;
	else cout << min(dp[n][0], dp[n][1]);
	                            
}


