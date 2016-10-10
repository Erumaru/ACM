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

void solve ()
{
	scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
	for (int i = 1, a, b, len; i <= m; i ++)
	{
		scanf("%d%d%d", &a, &b, &len);
		g[a].pb(mp(b, len));
	}
	for (int i = 1, a, b, len; i <= k; i ++)
	{
		scanf("%d%d%d", &a, &b, &len);
		
	}
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve();
}


