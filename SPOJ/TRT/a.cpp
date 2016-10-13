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

int n, a[2010];
ll dp[2010][2010];

ll go (int l, int r)
{
	if (l == r) return a[l] * (n);
	if (dp[l][r] != -1) return dp[l][r];
	int time = (n - r) + l;
	return dp[l][r] = max(go(l + 1, r) + a[l] * time, go(l, r - 1) + a[r] * time);
}

int main ()
{      
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	memset(dp, -1, sizeof dp);
	printf("%lld\n", go(1, n));	
}


