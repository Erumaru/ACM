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

int n, k, a[1001000], p[1001000];

int main ()
{      
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	scanf("%d", &k);

	int h = 0, t = 0;
	for (int i = 1; i <= n; i ++)
	{
		while (h < t && p[t - 1] < a[i]) t --;
		p[t ++] = a[i];
		if (i >= k)
		{
			printf("%d ", p[h]);
			if (p[h] == a[i - k + 1]) h ++;
		} 
	}	
}


