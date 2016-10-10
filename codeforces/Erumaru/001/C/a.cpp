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

string s;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;

	if (sz(s) == 2)
	{
		if (s[0] == s[1])
		{
			if (s[1] != min('z', char(s[0] + 1))) s[0] ++;
			else if (s[1] != max('a', char(s[0] - 1))) s[0] --;
		}
		cout << s;
		return 0;
	}

	for (int i = 1; i < sz(s) - 1; i ++)
	{
		if (s[i - 1] == s[i] && s[i + 1] == s[i])
		{
			char mx = max(s[i - 1], s[i + 1]), mn = min(s[i + 1], s[i - 1]);
			if (s[i - 1] != max('a', char(mx - 1)) && s[i + 1] != max('a', char(mx - 1))) s[i] = mx - 1;
			else if (s[i - 1] != max('a', char(mn - 1)) && s[i + 1] != max('a', char(mn - 1))) s[i] = mn - 1;
			else if (s[i - 1] != min('z', char(mx + 1)) && s[i + 1] != min('z', char(mx + 1))) s[i] = mx + 1;
			else if (s[i - 1] != min('z', char(mn + 1)) && s[i + 1] != min('z', char(mn + 1))) s[i] = mn + 1;
			else assert(false);
		}
	}

	for (int i = 1; i < sz(s) - 1; i ++)
	{
		if (s[i - 1] == s[i] || s[i + 1] == s[i])
		{
			char mx = max(s[i - 1], s[i + 1]), mn = min(s[i + 1], s[i - 1]);
			if (s[i - 1] != max('a', char(mx - 1)) && s[i + 1] != max('a', char(mx - 1))) s[i] = mx - 1;
			else if (s[i - 1] != max('a', char(mn - 1)) && s[i + 1] != max('a', char(mn - 1))) s[i] = mn - 1;
			else if (s[i - 1] != min('z', char(mx + 1)) && s[i + 1] != min('z', char(mx + 1))) s[i] = mx + 1;
			else if (s[i - 1] != min('z', char(mn + 1)) && s[i + 1] != min('z', char(mn + 1))) s[i] = mn + 1;
			else assert(false);
		}
	}

	cout << s;
}
