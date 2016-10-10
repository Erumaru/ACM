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

ll n, a[100100], p[100100], d[100100], sz[100100], mx;
vector <ll> v;
bool u[100100];

int get(int x)
{
	if (d[x] == x) return x;
	return d[x] = get(d[x]);
}

void unite(int a, int b)
{
	a = get(a);
	b = get(b);
	if (a == b) return;
	if (rand() & 1) swap(a, b);
	d[a] = b;
	sz[b] += sz[a];
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> p[i], d[i] = i, sz[i] = a[i];

	reverse(p + 1, p + 1 + n);
	sz[0] = -1;

	for (int i = 1; i <= n; i ++)
	{
		u[p[i]] = true;
		int l = 0, r = 0;
		if (p[i] > 1) 
		{
			if (u[p[i] - 1]) l = get(p[i] - 1);
		}
		if (p[i] < n)
		{
			if (u[p[i] + 1]) r = get(p[i] + 1);
		} 
		//cout << p[i] << " " << l << " " << r << "\n";
		//cout << mx << "\n";
		v.pb(mx);
		if (sz[l] != -1)
		{
			unite(l, p[i]);
		}
		if (sz[r] != -1)
		{
			unite(r, p[i]);
		} 
		mx = max(mx, sz[get(p[i])]);
	}       
	reverse(v.begin(), v.end());             
	for (int i = 0; i < sz(v); i ++) cout << v[i] << "\n";        
}


