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

#define f first
#define s second
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

int n, q, a[510][510], table[9][9][500][500], two[502];

void make_sparse()
{
	two[0] = -1;
	for (int i = 1; i <= n; i ++) two[i] = 1 + two[i / 2];

	for (int lvl1 = 0; (1 << lvl1) <= n; lvl1 ++)
	{
		for (int lvl2 = 0; (1 << lvl2) <= n; lvl2 ++)
		{
			for (int i = 1; i <= n; i ++)
			{
				for (int j = 1; j <= n; j ++)
				{
					if (lvl1 == 0 && lvl1 == lvl2) continue;
					if (lvl1 > lvl2) table[lvl1][lvl2][i][j] = 
						max(table[lvl1 - 1][lvl2][i][j], table[lvl1 - 1][lvl2][i + (1 << (lvl1 - 1))][j]);
					else table[lvl1][lvl2][i][j] = 
						max(table[lvl1][lvl2 - 1][i][j], table[lvl1][lvl2 - 1][i][j + (1 << (lvl2 - 1))]);
				}
			}
		}
	}
}

int get(int x, int y, int s)
{
	int lvl = two[s];
	int x2 = x + s - 1, y2 = y + s - 1;
	return max(max(table[lvl][lvl][x][y], table[lvl][lvl][x2 - (1 << lvl) + 1][y]),
		max(table[lvl][lvl][x][y2 - (1 << lvl) + 1], table[lvl][lvl][x2 - (1 << lvl) + 1][y2 - (1 << lvl) + 1]));
}

void solve(int test)
{
	memset(table, 0, sizeof table);
	printf("Case %d:\n", test);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
		{
			scanf("%d", &a[i][j]);
			table[0][0][i][j] = a[i][j];
		}
	}

	make_sparse();

	for (int i = 1, x, y, s; i <= q; i ++)
	{
		scanf("%d%d%d", &x, &y, &s);
		printf("%d\n", get(x, y, s));
	}
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 1; i <= test; i ++) solve(i);	
}


