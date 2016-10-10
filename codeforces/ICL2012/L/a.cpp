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
const double pi = acos(-1);

int n;
double a[1 << 17];
bool u[1 << 17];

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout); 

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    double mn = 0;
	int ind = 0;
    for (int i = n; i > 0; i --)
    {
    	double cur = a[i];
    	if (a[i] < pi / 2.0)
    	{
    		if (a[i] < mn)
    		{
    			mn = pi;
    			ind = 0;
    			continue;
    		}
    		else
    		{
    			u[i] = true;
    		}
    	}
    	else
    	{
    		cur = pi - a[i];
    		if (cur < mn)
    		{
    			mn = cur;
    			ind = i;
    		}
    		else u[i] = true;
    	}
    }
    mn = inf;
    ind = 0;
    for (int i = 1; i <= n; i ++)
    {
    	double cur = a[i];
    	if (cur > pi / 2.0)
    	{
    		cur = pi - a[i];
    		if (cur < mn)
    		{
    			mn = pi;
    			ind = 0;
    			continue;
    		}
    		else u[i] = true;
    	}
    	else
    	{
    		if (cur < mn)
    		{
    			mn = cur;
    			ind = i;
    		}
    		else u[i] = true;
    	}
    }                              

    vector <int> ans;
    for (int i = 1; i <= n; i ++) if (!u[i]) ans.pb(i);
    cout << sz(ans) << "\n";
	for (int i = 0; i < sz(ans); i ++) cout << ans[i] << " ";
}


