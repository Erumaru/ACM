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

vector<int> g[100100];
int pa[100100];
int used[100100];
int T;
int n, p, m;
bool dfs(int v){
	if(used[v] == T) return 0;
	used[v] = T;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(pa[to] == 0 || dfs(pa[to])){
			pa[to] = v;
			pa[v] = to;
			return 1;
		}
	}
	return 0;
}
int main ()
{      

	scanf("%d%d%d", &p,&n, &m);
	n += p;
	for(int i = 0, a, b; i < m; i++){
		scanf("%d%d", &a, &b);
		b += p;
		g[a].pb(b);
	}
	while(true){
		int changed = false;
		T++;
		for(int i = 1; i <= p; i++){
			if(used[i]!= T && pa[i] == 0 &&dfs(i)){
				changed = true;
			}
		}
		if(!changed) break;
	}
	int ans = 0;
	for(int i = p+1; i <= n; i++)
		if(pa[i] != 0) ans++;
	cout << ans << endl;
}


