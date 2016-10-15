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
typedef pair<ll, ll> pii;

const int N = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

ll a, b;

pii q[1001000];
map <ll, ll> mk;
int qh, qt;
vector <ll> ans;

int main ()
{      
	cin >> a >> b;
	q[qt ++] = mp(a, 0);
	while (qh < qt)
	{
		pii cur = q[qh ++];
		if ((mk.count(cur.ft) && mk[cur.ft] <= cur.st) || cur.ft > b) continue;
		mk[cur.ft] = cur.st;
		q[qt ++] = mp(cur.ft * 2, cur.st + 1);
		q[qt ++] = mp(cur.ft * 10 + 1, cur.st + 1);
	}	

	if (!mk.count(b)) cout << "NO";
	else
	{
		cout << "YES\n";
		int cur = b;
		while (true)
		{
			ans.pb(cur);
			if (cur == a) break;
			if (cur & 1)
			{
				cur /= 10;
			}
			else cur /= 2;
		}
		reverse(all(ans));
		cout << sz(ans) << "\n";
		for (int i = 0; i < sz(ans); i ++) cout << ans[i] << " ";
	}


}


