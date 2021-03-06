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

map <ll, ll> mk;
ll n;

ll go (ll n)
{
	if (n == 0) return 0;
	if (mk.count(n)) return mk[n];
	return mk[n] = max(n, go(n / 2) + go(n / 3) + go(n / 4));
} 

void solve()
{
	mk.clear();
	printf("%lld\n", go(n));
}

int test;

int main ()
{      
	while (~scanf("%lld", &n)) solve();
}


