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

int op(int a, int b, int c)
{
	if (c == 1) return a + b;
	else if (c == 2) return a * b;
	else if (c == 3) return a / b;
	else return a - b;
}

vector <int> v;

bool go(int res, int ind)
{
	if (ind == 8)
	{
		return (res == 159);
	}

	for (int i = 1; i <= 4; i ++)
	{
		if (i == 3 && res % 4) continue;
		if (go(op(res, 4, i), ind + 1)) 
		{
			cout << i << " ";
			return true; 
		}
	}
	return false;
}

int main ()
{      
	go(4, 1);
}


