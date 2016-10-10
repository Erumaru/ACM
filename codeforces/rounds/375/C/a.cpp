//#pragma comment(linker, "/STACK:64000000")
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

int n, a[2010], p[2010], m;
vector <int> g[2010];

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        

	cin >> n >> m;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		if (a[i] <= m) p[a[i]] ++;
	}

	int need = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (i % m == 0) need = i;
	}
	
	int cur = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (a[i] <= m) cur ++;
	}

	int ans = 0;
	p[0] = inf;
	for (int i = 1; i <= n; i ++)
	{
		if (cur >= need) break;
		if (a[i] > m) 
		{
			int mn = 0;
			for (int j = 1; j <= m; j ++)
			{
				if (p[mn] > p[j]) mn = j;
			}
			p[mn] ++;
			a[i] = mn;
			ans ++;
			cur ++;
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		if (a[i] <= m)
		{
			g[a[i]].pb(i);
		}
	}

	//cerr << need << "\n";
	//for (int i = 1; i <= m; i ++) cerr << p[i] << " ";

	int ansmin = need / m;
	for (int i = 1; i <= m; i ++)
	{
		while (p[i] < ansmin)
		{
			//cerr << i << " " << p[i] << "\n";
			for (int j = 1; j <= m; j ++)
			{
				if (i == j) continue;
				if (p[j] > ansmin)
				{
					p[i] ++;
					p[j] --;
					int curmus = g[j].back();
					a[curmus] = i;
					break;
				}
			}
			ans ++;
		}
	}

	cout << ansmin << " " << ans << "\n";

	for (int i = 1; i <= n; i ++) cout << a[i] << " ";


}


