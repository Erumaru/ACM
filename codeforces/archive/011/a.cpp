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
int n, cost, a[110], total, br;
string name;
double tot;

int main ()
{      
	freopen("flat.in", "r", stdin);
	freopen("flat.out", "w", stdout);
	cin >> n >> cost;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> name;
		if (name == "bedroom") br += a[i];
		if (name == "balcony") tot += (a[i] / 2.0);
		else tot += a[i];
		total += a[i];
	}

	printf("%d\n%d\n%.12f", total, br, tot * cost);
}


