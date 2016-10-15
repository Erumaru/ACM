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

int n, f[100010], cnt[100100], k[100100];
priority_queue <pair<int, pii> > p;
vector <pii> ans;

int main ()
{      
	scanf("%d", &n);
	
	for (int i = 0, d, s; i < n; i ++)
	{
		scanf("%d%d", &d, &s);
		if (d == 0) continue;
		p.push(mp(-d, mp(s, i)));
		cnt[i] = d;
		k[i] = s;
	}


	while (!p.empty())
	{
		int v = p.top().st.st, x = p.top().st.ft, d = -p.top().ft;
		p.pop();
		if (cnt[v] != d || k[v] != x) continue;
		if (cnt[v] == 0) continue;
		int cur = k[v];
		ans.pb(mp(v, cur));
		k[cur] ^= v;
		k[v] = 0;
		cnt[cur] --;
		cnt[v] = 0;
		if (cnt[cur] == 0) continue;
		p.push(mp(-cnt[cur], mp(k[cur], cur)));
	}

	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i ++) printf("%d %d\n", ans[i].ft, ans[i].st);
}


