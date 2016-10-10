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
		if (i < z[j] + j) z[i] = min(z[i - j], z[j] + j - i);
		while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i] ++;
		if (z[i] + i > z[j] + j) j = i;
	}
	return z;
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        
	cin >> n >> k;
	cin >> s;
	z = zf(s);

	for (int i = 0; i < n; i ++)
	{
		if (i < k) continue;
		if ((i + 1) % k == 0)
		{
			int x = (i + 1) / l;
			if (x + z[x] >= i) p[i] = 1;
		}
		if ((i + 1) % (k + 1) == 0)
		{
			int x = (i + 1) / (k + 1);
			if (x + z[x] >= i) p[i] = 1;
		}

		if ((i + 1) % (2 * k + 1))
		{
			int x = (i + 1) / (2 * k);

		}
	}
}


