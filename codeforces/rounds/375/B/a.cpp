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

int  n, ans1, ans2;
string cur, s;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        
	cin >> n;
	cin >> s;
	string cur = "";
	bool ok = false;
	for (int i = 0; i < sz(s); i ++)
	{
		if (s[i] == '_')
		{
			if (sz(cur))
			{	
				if (!ok) ans1 = max(ans1, sz(cur));
				else ans2 ++;
			}
			cur = "";
		}
		else if (s[i] == '(')
		{
			ok = true;
			if (sz(cur))
			{
				ans1 = max(ans1, sz(cur));
			}
			cur = "";
		}
		else if (s[i] == ')')
		{
			ok = false;
			if (sz(cur))
			{
				ans2 ++;
			}
			cur = "";
		}
		else cur += s[i];
		//cout << cur << "\n";
	}
	if (sz(cur))
	{
		ans1 = max(ans1, sz(cur));
	}

	cout << ans1 << " " << ans2 << "\n";
	
}


