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

int n, a[1010], m;
pii b[1010];
vector <int> g[1010];

int main ()
{
	freopen("dice.in", "r", stdin);      
	freopen("dice.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i], m += a[i], b[i] = mp(a[i], i);

	sort(b + 1, b + 1 + n);

	double ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		double cur = 1.0 / b[i].ft;
		for (int j = 1; j <= b[i].ft; j ++)
		{
			ans += cur * m;
			g[b[i].st].pb(m);
			m --;
		}
	}

	printf("%.5f\n", ans);
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < sz(g[i]); j ++) cout << g[i][j] << " ";
		cout << "\n";
	}
}


