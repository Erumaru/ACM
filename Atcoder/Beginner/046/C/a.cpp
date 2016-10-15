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

long long n, t[1010], a[1010];
__int128 aa[1100], tt[1010];

int main ()
{      
	cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> t[i] >> a[i];
		tt[i] = t[i];
		aa[i] = a[i];
	}

	__int128 A = 1, B = 1;

	for (int i = 1; i <= n; i ++)
	{
		__int128 l = 0, r = (1e18) + 1, k;
		while (l <= r)
		{
			__int128 mid = (l + r) / 2;
			if (t[i] * mid >= A && a[i] * mid >= B) k = mid, r = mid - 1;
			else l = mid + 1;
		}

		A = t[i] * k;
		B = a[i] * k;
		//cout << A << " " << B << "\n";
	}

	ll P = A + B;
	cout << P << "\n";
}


