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

int n, a[600100];
ll M;

int main ()
{      
	scanf("%d%lld", &n, &M);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	for (int i = 1; i <= n; i ++) a[i + n] = a[i]; 
	ll cur = 0, ans = 0;
	for (int i = 1, j = 1; i <= 2 * n; i ++)
	{
		cur += a[i];
		while ((j <= i && cur > M) || (i - j + 1) > n) cur -= a[j ++];
		ans = max(ans, cur);
	}	
	printf("%lld\n", ans);
}


