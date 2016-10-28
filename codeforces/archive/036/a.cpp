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

ll n;
char c;

int main ()
{      
	scanf("%lld%c", &n, &c);
	ll d = (n - 1) / 4 * 2 * 6 * 4;
	if (n != 1 && n & 1) d ++;
	n %= 4;
	if (n % 2 == 0) d += 7;
	if (c == 'f') d ++;
	else if (c == 'e') d += 2;
	else if (c == 'd') d += 3;
	else if (c == 'a') d += 4;
	else if (c == 'b') d += 5;
	else d += 6;

	printf("%lld\n", d);
}


