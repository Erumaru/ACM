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

int n, a[10010];
ll dp[10010];

void solve(int test)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	for (int i = 1; i <= n; i ++) dp[i] = 0;
	dp[1] = a[1];
	for (int i = 2; i <= n; i ++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
	}

	printf("Case %d: %lld\n", test, dp[n]);
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve(i);	
}


