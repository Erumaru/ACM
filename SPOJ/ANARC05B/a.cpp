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

int n, m, a[4][10010], dp[10010][4], was[10010][4], T, p[5];
map <int, int> pos[5];

int go (int x, int d)
{
	if (was[x][d] == T) return dp[x][d];
	if (x == p[d] + 1) return 0;
	was[x][d] = T;
	int res = -inf;
	res = max(res, go(x + 1, d) + a[d][x]);
	int next = -1;
	if (pos[d ^ 1].count(a[d][x])) next = pos[d ^ 1][a[d][x]];
	if (next != -1) res = max(res, go(next + 1, d ^ 1) + a[d][x]);
	return dp[x][d] = res;
}

void solve ()
{
	if (p[0] == 0) return;
	T ++;
	for (int i = 0; i <= 1; i ++) pos[i].clear();
	for (int i = 1; i <= p[0]; i ++) scanf("%d", &a[0][i]);
	
	sort(a[0] + 1, a[0] + 1 + p[0]);
	for (int i = 1; i <= p[0]; i ++) pos[0][a[0][i]] = i; 

	scanf("%d", &p[1]);
	for (int i = 1; i <= p[1]; i ++) scanf("%d", &a[1][i]);

	sort(a[1] + 1, a[1] + 1 + p[1]);
	for (int i = 1; i <= p[1]; i ++) pos[1][a[1][i]] = i;

	printf("%d\n", max(go (1, 0), go (1, 1)));
}

int main ()
{      
	while (~scanf("%d", &p[0])) solve();
}


