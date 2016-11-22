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

const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

int n, m, a[1010][1010], r[1010][1010], l[1010][1010], up[1010][1010], down[1010][1010];

int main ()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
    {
    	for (int j = 1; j <= m; j ++)
    	{
    		scanf("%d", &a[i][j]);
    	}
    }

    for (int i = 1; i <= n; i ++)
    {
    	for (int j = 1; j <= m; j ++)
    	{
    		l[i][j] = l[i][j - 1] + a[i][j];
    	}
    }

    for (int i = 1; i <= n; i ++)
    {
    	for (int j = m; j > 0; j --)
    	{
    		r[i][j] = r[i][j + 1] + a[i][j];
    	}
    }

    for (int i = 1; i <= m; i ++)
    {
    	for (int j = 1; j <= n; j ++)
    	{
    		up[j][i] = up[j - 1][i] + a[j][i];
    	}
    }

    for (int i = 1; i <= m; i ++)
    {
    	for (int j = n; j > 0; j --)
    	{
    		down[j][i] = down[j + 1][i] + a[j][i];
    	}
    }

    int res = 0;
    for (int i = 1; i <= n; i ++)
    {
    	for (int j = 1; j <= m; j ++)
    	{
    		if (a[i][j] == 1) continue;
    		if (up[i][j]) res ++;
    		if (down[i][j]) res ++;
    		if (l[i][j]) res ++;
    		if (r[i][j]) res ++;
    	}
    }

    printf("%d\n", res);

}

