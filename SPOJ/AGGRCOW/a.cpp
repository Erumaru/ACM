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

int n, c, x[100100];

bool ok(int d)
{
	int cur = c;
	int last = -inf;
	for (int i = 1; i <= n; i ++)
	{
		if (x[i] - last >= d) last = x[i], cur --;
	}

	return cur <= 0;
}

void solve ()
{	
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i ++) scanf("%d", x + i);
	sort(x + 1, x + n + 1);

	int l = 0, r = inf;
	int ans;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (ok(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}

	printf("%d\n", ans);
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();
}


