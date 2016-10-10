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

bool p[100100], d[100100];
vector <int> v;
int l, r;

void solve()
{
	scanf("%d%d", &l, &r);

	memset(d, false, sizeof d);
	for (int i = 0; i < sz(v); i ++)
	{
		int cur = v[i];
		int L = (l / cur + (l % cur != 0)) * cur;
		if (cur > r) break;
		for (int j = L; j <= r; j += cur)
		{
			if (j != cur) 
			{
				d[j - l] = true;
			}
		}
	}
 
	for (int i = 0; i < r - l + 1; i ++)
	{
		if (!d[i]) printf("%d ", i + l);
	}
	printf("\n");
}

int test;

int main ()
{      
	scanf("%d", &test);
	for (int i = 2; i <= 1e5; i ++)
	{
		if (!p[i])
		{
			for (int j = i + i; j <= 1e5; j += i) p[j] = true;
		}
	}

	for (int i = 2; i <= 1e5; i ++) if (!p[i]) v.pb(i);

	for (int i = 1; i <= test; i ++) solve();
}


