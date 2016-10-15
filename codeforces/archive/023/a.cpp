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

const int MAXN = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e9 + 7;


 
struct edge {
	int a, b, cap, flow;
};
 
int n, ss, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = ss;
	memset (d, -1, sizeof d);
	d[ss] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (ss, INF))
			flow += pushed;
	}
	return flow;
}

int num (string s)
{
	if (s == "S") return 1;
	if (s == "M") return 2;
	if (s == "L") return 3;
	if (s == "XL") return 4;
	if (s == "XXL") return 5;
	return 6;
}

string pp(int x)
{
	if (x == 1) return "S";
	if (x == 2) return "M";
	if (x == 3) return "L";
	if (x == 4) return "XL";
	if (x == 5) return "XXL";
	return "XXXL";
}

int p[20], yy[100100];
string s;

int main ()
{      
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	for (int i = 1; i <= 6; i ++) cin >> p[i];
	cin >> n;
	for (int i = 1; i <= 6; i ++) add_edge(n + i, n + 10, p[i]);
	ss = 0, t = n + 10;
	for (int i = 1; i <= n; i ++)
	{
		cin >> s;
		add_edge(0, i, 1);
		string cur = "";
		for (int j = 0; j < sz(s); j ++)
		{
			if (s[j] == ',') 
			{
				add_edge(i, n + num(cur), 1);
				cur = "";
				continue;
			}
			cur += s[j];
		}
		add_edge(i, n + num(cur), 1);
	}

	int ans = dinic();
	if (ans == n)
	{
		cout << "YES\n";
		
		for (int i = 0; i < sz(e); i ++)
		{
			if (e[i].cap != 1) continue;
			if (e[i].flow != 1) continue;
			if (e[i].a == 0) continue;
			if (e[i].b == n + 10) continue;
			yy[e[i].a] = e[i].b - n;
		}

		for (int i = 1; i <= n; i ++) cout << pp(yy[i]) << "\n";

	}
	else cout << "NO\n";

}


