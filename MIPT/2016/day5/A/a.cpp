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

int n;
string s[60];

bool check()
{
	for (int i = 1; i < n; i ++)
	{
		if (s[i][0] != s[i + 1][0] && s[i][1] != s[i + 1][1]) return false;
	}
	return true;
}

void solve()
{
	for (int i = 1; i <= n; i ++)
	{
		cin >> s[i];
	}

	for (int i = 1; i <= n * 10000; i ++)
	{
		random_shuffle(s + 1, s + n + 1);
		if (check())
		{
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main ()
{

	

	while (cin >> n) solve();	
}
