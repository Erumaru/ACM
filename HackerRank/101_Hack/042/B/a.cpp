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

int n, q, x[20], y[20];

int main ()
{      
	cin >> q;

	while (q --)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++)
		{
			cin >> x[i] >> y[i];
		}

		int top = inf, bot = -inf, left = inf, right = -inf;
		for (int i = 1; i <= n; i ++)
		{
			top = min(y[i], top);
			bot = max(y[i], bot);
			left = min(left, x[i]);
			right = max(right, x[i]);
		}
	
		//cout << top << " " << bot << " " << left << " " << right << "\n";
		bool ok = true;

		for (int i = 1; i <= n; i ++)
		{
			if ((x[i] != left && x[i] != right) && (y[i] != top && y[i] != bot))
			{
				cout << "NO\n";
				ok = false;
				continue;
			}
		}

		if (!ok) continue;
		cout << "YES\n";
	}
}


