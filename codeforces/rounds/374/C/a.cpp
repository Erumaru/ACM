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

int n, m, T, d[5010][5010], ans, came[5010][5010];
vector <pii> g[5010];
vector <int> v;
void dfs(int v, int p, ll t, int k)
{
	//cout << v << " " << p << " " << t << " " << k << "\n";
	if (t > T) return;
	if (d[v][k] > t || d[v][k] == -1)
	{
		came[v][k] = p;
		d[v][k] = t;
	}
	else return;
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i].ft, len = g[v][i].st;
		if (to != p)
		{
			dfs(to, v, t + len, k + 1);
		}
	}
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> T;
	for (int i = 1, u, v, t; i <= m; i ++)
	{
		cin >> u >> v >> t;
		g[u].pb(mp(v, t));
	}	               

	memset(d, -1, sizeof d);
	dfs(1, 0, 0, 0);             

	for (int i = n; i > 0; i --)
	{

		if (d[n][i] != -1)
		{
			ans = i;
			break;
		}
	}



	for (int p = n; p != 0;)
	{
		//cerr << p << "\n";
		v.pb(p);
		p = came[p][ans];
		ans --;
	}

	reverse(v.begin(), v.end());
	cout << sz(v) << "\n";
	for (int i = 0; i < sz(v); i ++) cout << v[i] << " ";
}


