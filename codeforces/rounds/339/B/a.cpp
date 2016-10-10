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

int cnt, zeros, n;
string s, ans;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	            

	cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> s;
		cnt = 0;
		bool ok = false;
		for (int j = 0; j < sz(s); j ++)
		{
			if (s[j] != '1' && s[j] != '0')
			{
				ok = true;
				ans = s;
			}
			else if (s[j] == '1') cnt ++;
		
		}
		if (ok)
		{
			ans = s;
		}
		else
		{
			if (cnt > 1)
			{
				ans = s;
			}
			else if (cnt < 0)
			{
				ans = "0";
			}
		}
	}

	if (ans[0] == '0')
	{
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= zeros; i ++) ans.pb('0');
	cout << ans;
}


