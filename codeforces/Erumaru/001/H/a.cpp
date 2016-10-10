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

ll t, a, b, lp[5000100], p[5000100];

int get(int x)
{
	int res = 0;
	while (x > 1)
	{
		res ++;
		x /= lp[x];
	}
	return res;
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= 5e6; i ++)
	{
		if (!lp[i])
		{
			lp[i] = i;
			for (int j = i + i; j <= 5e6; j += i)
			{
				if (!lp[j]) lp[j] = i;
			}
		}
	}  

	for (int i = 1; i <= 5e6; i ++) p[i] = get(i), p[i] += p[i - 1];      

	cin >> t;
	for (int i = 1; i <= t; i ++)
	{
		cin >> a >> b;

		cout << p[a] - p[b] << "\n";
	}                  
}


