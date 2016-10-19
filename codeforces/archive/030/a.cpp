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

int n, a[5010];
bool ok;
string s;

void no ()
{
	cout << -1;
	exit(0);
}

int dfs(int v, int x)
{
	a[v] = x;
	if (x >= n || x < 0) ok = false;
	if (v != 0 && v != sz(s))
	{
		if (s[v - 1] == '>')
		{
			if (s[v] == '>') 
			{
				a[v] = dfs(v + 1, x - 1) + 1;
				return a[v];
			}
			else if (s[v] == '<') 
			{
				a[v] = 0;
				dfs(v + 1, 1);
				return 0;
			}
			else
			{
				a[v] = min(x, dfs(v + 1, x));
				return a[v];
			}
		}
		else if (s[v - 1] == '<')
		{
			if (s[v] == '>')
			{
				a[v] = n - 1;
				dfs(v + 1, n - 2);
				return n - 1;
			}
			else if (s[v] == '<')
			{	
				a[v] = x;
				dfs(v + 1, x + 1);
				return x;
			}
			else
			{
				a[v] = x;
				dfs(v + 1, x);
				return x;
			}
		}
	}
	return a[v];
}

void ans()
{
	for (int i = 0; i <= sz(s); i ++)
	{
		cout << char(a[i] + 'a');
	}
	exit(0);
}

int main ()
{      
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i ++)
	{
		ok = true;
		dfs(0, i);
		if (ok) ans();
	}

	no();

	return 0;
}


