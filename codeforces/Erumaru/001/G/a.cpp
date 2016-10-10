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

ll v, a[1 << 5];
vector <int> ans;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> v;
	ll mn = INF;
	for (int i = 1; i <= 9; i ++) cin >> a[i], mn = min(mn, a[i]);
	for (int i = 9; i > 0; i --)
	{
		if (a[i] == mn)
		{
			while (v >= a[i])
			{	
				ans.pb(i);
				v -= a[i];
			}
			break; 
		}
	}

	if (sz(ans) == 0)
	{
		cout << -1;
		return 0;
	}

	for (int i = 0; i < sz(ans); i ++)
	{
		for (int j = 9; j > ans[i]; j --)
		{
			if (v + a[ans[i]] - a[j] >= 0)
			{
				//cout << v + a[ans[i]] - a[j] << " " << i << " " << ans[i] << " " << j << "\n";
				v = v + a[ans[i]] - a[j];
				ans[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < sz(ans); i ++) cout << ans[i];
}


