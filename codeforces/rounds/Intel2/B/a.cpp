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

int n, m, a[30][30], tmp[30][30];

bool check(int x, int y)
{
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			tmp[i][j] = a[i][j];
		}
	}

	for (int i = 1; i <= n; i ++) swap(tmp[i][x], tmp[i][y]);

	for (int i = 1; i <= n; i ++)
	{
		int cur = 0;
		for (int j = 1; j <= m; j ++)
		{
			if (j != tmp[i][j]) cur ++;
		}
		if (cur > 2) return false;
	}
	return true;
}

void yes()
{
	cout << "YES";
	exit(0);
}

void no()
{
	cout << "NO";
	exit(0);
}

int main ()
{      
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= m; i ++)
	{
		for (int j = i; j <= m; j ++)
		{
			if (check(i, j)) yes();
		}
	}
	no();
}


