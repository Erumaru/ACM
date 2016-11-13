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

int main ()
{      
	scanf("%d%d%d", &n, &m, &r);

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++) 
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			scanf("%d", &w[i][j]);
		}
	}

	for (int i = 1; i <= r; i ++)
	{
		for (int j = 1; j <= 6; j ++) 
		{
			scanf("%d", &p[i][j]);
		}	
	}

		
}


