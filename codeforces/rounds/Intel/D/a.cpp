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

int a[50100], p[50010], n, ans;
map <int, int> mk;
vector <int> v;

bool can(int x)
{
	mk.clear();
	for (int i = 1; i <= n; i ++)
	{
		int cur = a[i];
		while (cur >= 1)
		{
			if (!mk.count(cur) && cur <= x)
			{
				mk[cur] = cur;
				break;
			}
			cur /= 2;
		}
		if (mk[cur] != cur) return false;
	}
	return true;
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
	{
		int cur = a[i];
		while (cur >= 1)
		{
			v.pb(cur);
			cur /= 2;
		}
	}

	sort(v.begin(),v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	cerr << 1;
	int l = 0, r = sz(v) - 1;

	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (can(v[mid])) r = mid - 1, ans = v[mid];
		else l = mid + 1;
	}

	mk.clear();

	for (int i = 1; i <= n; i ++)
	{
		int cur = a[i];
		while (cur >= 1)
		{
			if (!mk.count(cur) && cur <= ans)
			{
				p[i] = cur;
				mk[cur] = cur;
				break;
			}
			cur /= 2;
		}
	}

	for (int i = 1; i <= n; i ++) cout << p[i] << " "; 


}


