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

map <pii, int> mk, w;
int ans, k, id1, id2;

void get(int a, int b, int c, int id)
{
	if (mk.count(mp(a, b)))
	{
		int cur = min(a, min(b, c + mk[mp(a, b)]));
		if (ans < cur)	
		{
			ans = cur;
			k = 2;
			id1 = id;
			id2 = w[mp(a, b)];
		}
	}
	if (mk.count(mp(a, c)))
	{
		int cur = min(a, min(c, b + mk[mp(a, c)]));
		if (ans < cur)	
		{
			ans = cur;
			k = 2;
			id1 = id;
			id2 = w[mp(a, c)];
		}
	}

	if (mk.count(mp(b, c)))
	{
		int cur = min(b, min(c, a + mk[mp(b, c)]));
		if (ans < cur)	
		{
			ans = cur;
			k = 2;
			id1 = id;
			id2 = w[mp(b, c)];
		}
	}
}

int n, a[100100], b[100100], c[100100];

int main ()
{      
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d%d", a + i, b + i, c + i);
		int cur = min(a[i], min(b[i], c[i]));
		if (cur > ans)
		{
			ans = cur;
			k = 1;
			id1 = i;
		}
	}

	for (int i = 1; i <= n; i ++)
	{
		get(a[i], b[i], c[i], i);
		if (c[i] > mk[mp(a[i], b[i])]) 
		{
			mk[mp(a[i], b[i])] = c[i];
			w[mp(a[i], b[i])] = i;
		}
		if (c[i] > mk[mp(b[i], a[i])]) 
		{
			mk[mp(b[i], a[i])] = c[i];
			w[mp(b[i], a[i])] = i;
		}
		if (b[i] > mk[mp(a[i], c[i])]) 
		{
			mk[mp(a[i], c[i])] = b[i];
			w[mp(a[i], c[i])] = i;
		}
		if (b[i] > mk[mp(c[i], a[i])]) 
		{
			mk[mp(c[i], a[i])] = b[i];
			w[mp(c[i], a[i])] = i;
		}
		if (a[i] > mk[mp(c[i], b[i])]) 
		{
			mk[mp(c[i], b[i])] = a[i];
			w[mp(c[i], b[i])] = i;
		}
		if (a[i] > mk[mp(b[i], c[i])]) 
		{
			mk[mp(b[i], c[i])] = a[i];
			w[mp(b[i], c[i])] = i;
		}
	}

	cout << k << "\n";
	if (k == 1) cout << id1 << "\n";
	else
	{
		cout << id1 << " " << id2 << "\n";
	}
}


