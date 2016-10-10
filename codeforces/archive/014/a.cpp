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

void imp()
{
	cout << "Impossible";
	exit(0);
}

void amb()
{
	cout << "Ambiguous";
	exit(0);
}

void uni()
{
	cout << "Unique";
	exit(0);
}

int n, m, s, k;
string t;
int cnt, comp;

int main ()
{      
	freopen("black.in", "r", stdin);
	freopen("black.out", "w", stdout);
	cin >> n >> m >> s >> k;
	cin >> t; 
	t = "." + t + ".";
	for (int i = 0; i < sz(t) - 1; i ++)
	{
		if (t[i] == '.' && t[i + 1] == '*') comp ++;
		if (t[i] == '*')
		{
			cnt ++;
		}
	}
	if (comp > 1) imp();
	if (s == n && comp == 0) imp();
	if (k - 1 < s && n - k < s && comp == 0) imp(); 
	if (cnt > 0 && cnt != s) imp();
	if (s == 1 && cnt == 1) uni();
	if (cnt > 0 && (k == 1 || k == n)) uni();
	if (s == n) uni();
	if (comp == 0)
	{
		if (k - 1 < s && n - k == s) 
		{
			if (s == m) uni();
			else amb();
		}
		else if (n - k < s && k - 1 == s) 
		{
			if (s == m) uni();
			else amb();
		}
		else amb();
	}
	amb();
}


