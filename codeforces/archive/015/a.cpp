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


int n, m, dp[(1 << 18) + 10][19], b[(1 << 18) + 1], g[29][20];
pii from[(1 << 18) + 10][19], p[(1 << 18) + 10];
priority_queue <pair <int, pair <int, int> > > q;


void rec(pii cur)
{
	vector <int> ans;
	int mask = cur.ft, ind = cur.st;
	while (mask > 0)
	{
		ans.pb(ind);
		int newmask = from[mask][ind].ft;
		ind = from[mask][ind].st;
		mask = newmask;
	}
	reverse(all(ans));

	cout << sz(ans) - 1 << " "; 
	for (int i = 0; i < sz(ans); i ++) cout << ans[i] + 1<< " ";
	cout << "\n";
}

int main ()
{
	freopen("immediate.in", "r", stdin);
	freopen("immediate.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);                                        
    cin >> n >> m;
    for (int i = 1, a, b, len; i <= m; i ++)
    {
    	cin >> a >> b >> len;
    	a --;
    	b --;
    	g[a][b] = len;
    	g[b][a] = len;
    }

    memset(dp, -1, sizeof dp);
    dp[1][0] = 0;
    q.push(mp(0, mp(1, 0)));
    
    while (!q.empty())
    {
    	int mask = q.top().st.ft, cur = q.top().st.st, val = - q.top().ft;
    	q.pop();
    	if (val != dp[mask][cur]) continue;
    	for (int to = 0; to < n; to ++)
    	{
    		if (cur == to) continue;
    		if (g[cur][to] == 0) continue;
    		int newmask = mask | (1 << to);
    		if (dp[newmask][to] == -1 || dp[newmask][to] > dp[mask][cur] + g[cur][to])
    		{
    			from[newmask][to] = mp(mask, cur);
    			dp[newmask][to] = dp[mask][cur] + g[cur][to];
    			q.push(mp(-dp[newmask][to], mp(newmask, to)));
    		}
    	}
    }


    for (int mask = 0; mask < (1 << n); mask ++)
    {
    	b[mask] = -1;
    	for (int i = 0; i < n; i ++)
    	{
    		if (dp[mask][i] == -1) continue;
    		if (b[mask] == -1 || dp[mask][i] < b[mask])
    		{
    			b[mask] = dp[mask][i];
    			p[mask] = mp(mask, i);
    		}
    	}
    }


    for (int mask = (1 << n) - 1; mask >= 0; mask --)
    {
    	if (b[mask] == -1) continue;
    	for (int i = 0; i < n; i ++)
    	{
    		if (!(mask & (1 << i))) continue;
    		int newmask = mask ^ (1 << i);
    		if (b[newmask] == -1 || b[newmask] > b[mask])
    		{
    			p[newmask] = p[mask];
    			b[newmask] = b[mask];
    		}
    	}
    }

    int ans = inf;
    int p1, p2;
    for (int mask = 0; mask < (1 << n); mask ++)
    {
    	int mask2 = mask ^ ((1 << n) - 1);
    	if (b[mask] == - 1 || b[mask2] == -1) continue;
    	if (max(b[mask], b[mask2]) < ans)
    	{
    		ans = max(b[mask], b[mask2]);
    		p1 = mask, p2 = mask2;
    	}
    }

	cout << ans << "\n";

	rec(p[p1]);
	rec(p[p2]);   
}


