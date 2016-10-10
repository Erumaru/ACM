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

void go(int x)
{
	if (x == 0) return;
	if (x & 1)
	{
		cout << 1;
		return go(x - 1);
	}
	if (x == 2)
	{
		cout << 11;
	}
	else
	{
		cout << "[";
		go(x / 2);
		cout << "]";
	}
}

int n;

int main ()
{      
	cin >> n;
	go(n);
}


