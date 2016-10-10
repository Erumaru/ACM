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

vector <int> zf(const string &s)
{
	int n = sz(s);
	vector <int> z (n);
	for (int i = 1, j = 0; i < n; i ++)
	{
		if (i < z[j] + j) z[i] = min(z[i - j], z[j] + j - i);
		while (z[i] + i < n && s[z[i]] == s[z[i] + i]) z[i] ++;
		if (i + z[i] > j + z[j]) j = i;
	}
	return z;
}

vector <int> z;
string s;
int m, p[100010];

void solve()
{
	cin >> s;
	
	z = zf(s);
	int n = sz(s);
	for (int i = 0; i < n; i ++) p[i] = 0;
	p[n] = 1;
	for (int i = 1; i < n; i ++) p[z[i]] ++;
	for (int i = n; i >= 1; i --) p[i - 1] += p[i];

	cin >> m;
	for (int i = 0, k; i < m; i ++) 
	{
		cin >> k;
		cout << p[k] << " ";
	}
	cout << "\n";
}

int test;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        
	cin >> test;
	for (int i = 1; i <= test; i ++) solve();
}


