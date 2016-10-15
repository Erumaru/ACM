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

int ask(int i, int j)
{
	int x;
	cout << "? " << i << " " << j << "\n";
	fflush(stdout);
	cin >> x;
	return x; 
}

int a[6000], n;

int main ()
{      
	cin >> n;
	int mn = inf;
	int A = ask(1, 2), B = ask(2, 3), C = ask(1, 3);
	a[1] = (A - B + C) / 2;
	a[2] = A - a[1];
	a[3] = C - a[1];
	for (int i = 4; i <= n; i ++) 
	{
		a[i] = ask(1, i);
	}	

	for (int i = 4; i <= n; i ++)
	{
		a[i] -= a[1];
	}

	cout << "! ";
	for (int i = 1; i <= n; i ++) cout << a[i] << " ";
	return 0;
}


