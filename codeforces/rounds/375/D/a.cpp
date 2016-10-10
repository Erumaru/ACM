//#pragma comment(linker, "/STACK:64000000")
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

int n, m, k, ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s[110];
bool u[110][110];
vector <pair <int, pair <int, int> > > v;

bool ok(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int dfs(int x, int y)
{
	if (!ok(x, y)) return 0;
	if (u[x][y]) return 0;
	if (s[x][y] == '*') return 0;
	u[x][y] = true;
	int res = 0;
	for (int i = 0; i < 4; i ++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		res += dfs(xx, yy);
	}
	return res + 1;
}


void del(int x, int y)
{
	if (!ok(x, y)) return;
	if (s[x][y] == '*') return;
	s[x][y] = '*';
	for (int i = 0; i < 4; i ++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		del(xx, yy);
	}
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		s[i] = " " + s[i]; 
	}

	for (int i = 1; i <= n; i ++)
	{
		dfs(i, 1);
		dfs(i, m);
	}

	for (int i = 1; i <= m; i ++)
	{
		dfs(1, i);
		dfs(n, i);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			if (!u[i][j] && s[i][j] == '.')
			{
				int cur = dfs(i, j);
				v.pb(mp(cur, mp(i, j)));
				cnt ++;
			}
		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < sz(v); i ++)
	{
		if (cnt == k) break;
		cnt --;
		int cur = v[i].ft, x = v[i].st.ft, y = v[i].st.st;
		ans += cur;
		del(x, y);
	}

	cout << ans << "\n";

	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			cout << s[i][j];
		}
		cout << "\n";
	}

}


