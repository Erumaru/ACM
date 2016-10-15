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

double a, b, c, d;

int main ()
{      
	cin >> a >> b >> c >> d;
	double first = max(3.0 * a / 10.0, a - a / 250 * c);
	double second = max(3.0 * b / 10.0, b - b / 250 * d);
	if (first > second) cout << "Misha";
	else if (second > first) cout << "Vasya";
	else cout << "Tie";
}


