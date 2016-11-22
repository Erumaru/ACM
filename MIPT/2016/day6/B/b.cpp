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

const int N = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

int n, m;
vector<int> g[500500], gr[500500];
int used[500500];
vector<int> order;
vector<pii> e;
int col[500500], sz = 0;
int ans[500500];
vector<int> orig[500500];
int deg[500500];

void dfs(int v) {
	if (used[v]) return;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		dfs(g[v][i]);
	}
	order.pb(v);
}

void dfs2(int v, int cc) {
	if (col[v] != -1) return;
	col[v] = cc;
	for (int i = 0; i < gr[v].size(); i++) {
		dfs2(gr[v][i], cc);
	}
}

void solve(int type) {
	if (!type) {
		order.clear();
		for (int i = 0; i < n; i++) used[i] = 0;
		for (int i = 0; i < n; i++) {
			dfs(i);
		}
		reverse(all(order));
	} else {
		reverse(all(order));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			deg[g[i][j]]++;
		}
	}
	set<pii> s;
	for (int i = 0; i < n; i++) {
		s.insert(mp(deg[i], i));
	}
	for (int i = 0; i < n - 1; i++) {
		int v = order[i];
		// n - i
		assert(deg[v] == 0);
		s.erase(mp(deg[v], v));
		pii p = *s.begin();
		//cout << v << " = " << p.f << " " << p.s << endl;
		if (p.f == 0) {
			ans[v] = 0;
		}
		for (int j = 0; j < g[v].size(); j++) {
			int to = g[v][j];
			s.erase(mp(deg[to], to));
			deg[to]--;
			s.insert(mp(deg[to], to));
		}
	}
}

int main ()
{

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		g[x].pb(y);
		gr[y].pb(x);
		e.pb(mp(x, y));
	}

	order.clear();
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}

	reverse(all(order));
	for (int i = 0; i < n; i++) col[i] = -1;

	for (int i = 0; i < sz(order); i++) {
		int v = order[i];
		if (col[v] == -1) {
			dfs2(v, sz);
			sz++;
		}
	}

	for (int i = 0; i < n; i++) {
		orig[col[i]].pb(i);
	}

	for (int i = 0; i < sz; i++) {
		gr[i].clear();
		g[i].clear();
	}
	n = sz;
	for (int i = 0; i < e.size(); i++) {
		int x = e[i].f, y = e[i].s;
		if (col[x] == col[y]) {
			continue;
		}
		g[col[x]].pb(col[y]);
		gr[col[y]].pb(col[x]);
	}

	for (int i = 0; i < n; i++) {
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
		sort(all(gr[i]));
		gr[i].resize(unique(all(gr[i])) - gr[i].begin());
	}

	for (int i = 0; i < n; i++) ans[i] = 1;

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < g[i].size(); j++) {
	// 		cout << i << " - " << g[i][j] << endl;
	// 	}
	// }

	solve(0);

	for (int i = 0; i < n; i++) g[i] = gr[i];

	solve(1);

	vector<int> res;
	for (int i = 0; i < n; i++) {
		if (ans[i]) {
			for (int j = 0; j < orig[i].size(); j++) {
				res.pb(orig[i][j] + 1);
			}
		}
	}

	sort(all(res));

	printf("%d\n", sz(res));
	for (int i = 0; i < sz(res); i++) {
		if (i) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");

	return 0;
}
