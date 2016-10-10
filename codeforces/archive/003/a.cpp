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


vector <int> zf(string s)
{
	int n = sz(s);
	vector <int> z (n);
	for (int i = 1, j = 0; i < n; i ++)
	{
		if (i < j + z[j]) z[i] = min(z[i - j], z[j] + j - i);
		while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i] ++;
		if (i + z[i] > j + z[j]) j = i;
	}
	return z;
}

string s;
vector <int> z;
int t[4000100];

void build (int v, int tl, int tr)
{
	if (tl == tr) t[v] = z[tl];
	else
	{
		int mid = (tl + tr) / 2;
		build (2 * v, tl, mid);
		build (2 * v + 1, mid + 1, tr);
		t[v] = max(t[2 * v], t[2 * v + 1]);
	}
}

int get(int v, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return t[v];
	int mid = (tl + tr) / 2;
	return max(get(2 * v, tl, mid, l, r), get(2 * v + 1, mid + 1, tr, l, r));
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        
	cin >> s;
	z = zf(s);
	int n = sz(s);
	build (1, 0, n - 1);
	//for (int i = 0; i < n; i ++) cout << z[i] << " ";
	//cout << "\n";

	int ans = 0;
	for (int i = 2; i < n; i ++)
	{
		if (z[i] == sz(s) - i)
		{
			int cur = get(1, 0, n - 1, 1, i - 1);
			//cout << cur << " ";
			if (cur != inf && cur >= z[i]) 
			{
				ans = max(ans, z[i]);
			}
		}
	}

	if (ans == 0) cout << "Just a legend\n";
	else cout << s.substr(0, ans) << "\n";
}


