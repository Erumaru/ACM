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
	freopen("ate.in", "r", stdin);
	freopen("ate.out", "w", stdout);
	int a;
	cin >> a;
	int ans = 0;
	for (int b = 0; b <= 99; b ++)
	{
		for (int c = 0; c <= 99; c ++)
		{
			if (b + c > a) break;
			if (b + c == a) ans ++; 
		}
	}

	cout << ans;
}


