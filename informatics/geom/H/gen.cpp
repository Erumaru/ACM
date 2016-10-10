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
const double pi = acos(-1.0);

inline double sqr(double x) {
	return x * x;
}

struct pt
{
	double x, y;
	pt (){}
	pt (double x, double y) : x(x), y(y) {}

	void read()
	{
		cin >> x >> y;
	}

	double norm() {
		return sqrt(sqr(x) + sqr(y));
	}

	double const operator *(pt o) {
		return x * o.x + y * o.y;
	}
} A, B;

int get(int n) {
	return arc4random() % n;
}

int main ()
{

	srand(time(NULL));
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << get(21) - 10 << " " << get(21) - 10 << endl;
	cout << get(21) - 10 << " " << get(21) - 10 << endl;

	return 0;
}



