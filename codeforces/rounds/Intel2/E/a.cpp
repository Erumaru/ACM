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

ll ans;
int p[10010], s[10100], d[10010], n, c;
vector <int> can;

int main ()
{      
	cin >> n >> c;
	for (int i = 1; i <= n; i ++) cin >> p[i];
	for (int i = 1; i <= n; i ++) cin >> s[i];
	for (int i = 1; i <= n; i ++)
	{
		if (p[i] >= s[i])
		{
			ans += s[i];
			if (c) p[i] = (p[i] - s[i]) / c;
			s[i] = 0;
			can.pb(i);
			d[i] = n - i;
		}
		else if (c)
		{
			ans += p[i];
			s[i] -= p[i];
			p[i] = 0;
			int need = s[i] / c;
			while (!can.empty() && need)
			{
				int cur = can.back();
				int cc = min(need, min(d[cur], p[cur]));
				ans += c * cc;
				need -= cc;
				d[cur] -= cc;
				p[cur] -= cc;
				if (!d[cur] || !p[cur]) can.pop_back();
				s[i] -= c * cc;
			}
		}
		else
		{
			ans += p[i];
		}
	}

	can.clear();
	for (int i = 1; i <= n; i ++)
	{
		if (p[i]) can.pb(i);
		else if (s[i] && c)
		{	
			if (sz(can))
			{
				ans += s[i];
				int cur = can.back();
				d[cur] --;
				p[cur] --;
				if (!d[cur] || !p[cur]) can.pop_back();
			}
		}
	}

	cout << ans;
}	


