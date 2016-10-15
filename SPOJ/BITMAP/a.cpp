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

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m, dp[200][200];
char s[200][200];

bool ok (int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

struct node
{
	int x, y, z;
	node(){}
	node(int x, int y, int z) : x(x), y(y), z(z) {}
} q[500 * 500];

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < m; j ++) dp[i][j] = -1;
	}
	
	int qt = 0, qh = 0;
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			if (s[i][j] == '1') q[qt ++] = node(i, j, 0);
		}
	}

	while (qh < qt)
	{
		node cur = q[qh ++];
		if (!ok(cur.x, cur.y)) continue;
		if (dp[cur.x][cur.y] != -1 && dp[cur.x][cur.y] <= cur.z) continue;
		dp[cur.x][cur.y] = cur.z;
		for (int i = 0; i < 4; i ++)
		{
			int xx = cur.x + dx[i], yy = cur.y + dy[i];
			q[qt ++] = node(xx, yy, cur.z + 1);
		}
	}

	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}

int test;

int main ()
{      
	scanf("%d", &test);	
	for (int i = 1; i <= test; i ++) solve();
}


