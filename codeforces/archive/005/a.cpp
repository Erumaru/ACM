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

struct node
{	
	int leaf;
	int next[26];
} t[1000100];

int sz = 1, dp[10010], n, m, from[10010];
vector <string> ans;

void add(const string &s, int x)
{
	int v = 0;
	for (int i = 0; i < sz(s); i ++)
	{
		int c = tolower(s[i]) - 'a';
		if (t[v].next[c] == -1)
		{
			memset(t[sz].next, -1, sizeof t[sz].next);
			t[v].next[c] = sz ++;
		}
		v = t[v].next[c];
	}
	t[v].leaf = x;
}

string s, p[100010];

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        
	cin >> n;
	cin >> s;
	cin >> m;
	
	memset(t[0].next, -1, sizeof t[0].next);
	for (int i = 1; i <= m; i ++)
	{
		cin >> p[i];
		string cur = p[i];
		reverse(cur.begin(), cur.end());
		add(cur, i);
	}

	dp[0] = inf;
	for (int i = 1; i <= sz(s); i ++)
	{
		if (dp[i - 1] != 0)
		{
			int v = 0;
			for (int j = i - 1; j <= sz(s); j ++)
			{
				if (t[v].leaf != 0) 
				{
					dp[j] = t[v].leaf; 
					from[j] = i - 1;
				}
				if (t[v].next[s[j] - 'a'] == -1) break;
				v = t[v].next[s[j] - 'a'];
			}
		}
	}

	//cout << s << "\n";
	//for (int i = 0; i <= sz(s); i ++) cout << dp[i] << " ";

	for (int i = sz(s); i != 0; i = from[i])
	{
		ans.pb(p[dp[i]]);
	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < sz(ans); i ++) cout << ans[i] << " ";
}



