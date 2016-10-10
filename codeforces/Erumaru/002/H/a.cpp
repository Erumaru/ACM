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

ll g[5], ans1, ans2, mx = inf, tmp[5];

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 3; i ++) cin >> g[i], mx = min(mx, g[i]), ans1 += g[i] / 3;
	int p = 0;
	for (int i = 0; i < 3; i ++)
	{
		for (int j = 1; j <= 3; j ++)
		{
			if (g[j] < i) 
			{
				cout << ans1;
				return 0;
			}
		}
		ans2 = i;
		for (int j = 1; j <= 3; j ++) ans2 += (g[j] - i) / 3;
		ans1 = max(ans1, ans2);
	}

	cout << ans1;
	                            
}


