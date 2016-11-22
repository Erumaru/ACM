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

int n, k, s;
ll t;
int p[200100], c[200100], v[200100], pos[200100];

bool cmp (int i, int j)
{
	return v[i] < v[j] || (v[i] == v[j] && c[i] < c[j]);
}

ll get(ll a, ll b, ll cap)
{
	ll ans = -1;
	ll l = 0, r = min(cap / 2, b - a);
	//cout << a << " % " << b << "\n";
	//cout << cap << ":\n";
	//cout << l << " " << r << "\n";
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		//cout << mid << "\n";
		if (mid + (cap - mid * 2) >= (b - a)) ans = mid, l = mid + 1;
		else r = mid - 1;
		//cout << l << " & " << r << "\n";
	}
	//cout << "ans: " << ans << "\n";
	if (ans == -1) return -1;
	ll time = ans + (b - a - ans) * 2;
	return time;
}

bool ok(int x)
{
	x = pos[x];
	ll time = 0;
	for (int i = 0; i < k; i ++)
	{
		ll cur = get(p[i], p[i + 1], v[x]);
		if (cur == - 1) return false;
		time += cur;
		//cout << i << " " << i + 1 << " " << x << " " << cur << "\n";
	}
	return time <= t;
}

int main ()
{
    scanf("%d%d%d%lld", &n, &k, &s, &t);
    for (int i = 1; i <= n; i ++)
    {
    	scanf("%d%d", c + i, v + i);
    }

    for (int i = 1; i <= k; i ++)
    {
    	scanf("%d", p + i);
    }

    for (int i = 1; i <= n; i ++) pos[i] = i;

    sort(p + 1, p + 1 + k);
	p[++ k] = s;
    sort(pos + 1, pos + 1 + n, cmp);

    int ans = -1;
    int l = 1, r = n;
    while (l <= r)
    {
    	int mid = (l + r) / 2;
    	if (ok(mid)) ans = mid, r = mid - 1;
    	else l = mid + 1;
    }     
    if (ans != -1)
    {
    	ans = pos[ans];
    	ans = v[ans];
    	int mn = inf;
    	for (int i = 1; i <= n; i ++)
    	{
    		if (v[i] < ans) continue;
    		mn = min(c[i], mn);
    	}
    	ans = mn;
    }

    printf("%d\n", ans);
}