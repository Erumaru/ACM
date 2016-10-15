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

char s[7000], t[7000];
int dp[7000][7000];

void solve()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);

	for (int i = 1; i <= n; i ++) t[i] = s[i];
	reverse(t + 1, t + 1 + n);

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}

	printf("%d\n", n - dp[n][n]);
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();	
}


