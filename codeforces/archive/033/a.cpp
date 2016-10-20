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

int n, a[110], dp[110][110];

void go(int v, int p)
{
	for (int i = n; i >= 1; i --)
	{
		if (a[i] == 0) continue;
		if (i == v) continue;
		if (dp[v][i]) continue;
		cout << i << " " << i << " " << v << "\n";
		dp[v][i] = 1;
		a[i] --;
		return go(i, v);
	}
}

int main ()
{      
	cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		a[i] = n - 1;
	}
	a[1] --;
	cout << 1 << " " << 1 << " " << 0 << "\n";
	go (1, -1);	
	for (int i = 2; i <= n; i ++)
	{
		if (dp[i][1] == 0)
		{
			cout << 0 << " " << 1 << " " << i << "\n";
			return 0;
		}
	}
}


