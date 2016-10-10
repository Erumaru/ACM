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

ll dp[3010][3010], n, a[3010];
vector <ll> v;
map <ll, int> id;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	            
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i], a[i] -= i, v.pb(a[i]);                
	v.pb(-inf);
	sort(v.begin(), v.end());
	int sz = unique(v.begin(), v.end()) - v.begin();
	for (int i = 0; i < sz(v); i ++) id[v[i]] = i;

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j < sz; j ++)
		{
			dp[i][j] = dp[i - 1][j] + abs(a[i] - v[j]);
		}

		for (int j = 2; j < sz; j ++)
		{
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
	}

	ll ans = INF;
	for (int i = 1; i < sz; i ++)
	{
		ans = min(ans, dp[n][i]);
	}

	cout << ans;
}


