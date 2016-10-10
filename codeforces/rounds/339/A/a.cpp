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

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long double l, r, k;
	cin >> l >> r >> k;
	long double p = 1;
	bool ok = true;
	while (p < r + 1) 
	{
		if (p > l - 1 && p < r + 1) 
		{
			ll tp = p;
			cout << tp << " ", ok = false;
		}
		p *= k;
	}         
	if (ok) cout << -1;                 
}


