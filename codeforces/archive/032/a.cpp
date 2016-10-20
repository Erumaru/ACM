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

ll l, r, w; 

int main ()
{      
	cin >> l >> r >> w;
	ll d = __gcd(r, w);

	if (l - w + 1 > r - 1) 
	{
		cout << "OK";
		return 0;
	}
	if (r == 1 || l == 1) 
	{
		cout << "OK";
		return 0;
	}
	
	if (d == 1)
	{
		cout << "DEADLOCK";
		return 0;
	}
	
	ll tl = l - w, tr = r - 1;

	if (tr / d > tl / d)
	{
		cout << "DEADLOCK";
		return 0;
	}


	cout << "OK";
	return 0;
}


