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

int n, p[1001], a[1001];

int main ()
{      
	while (~scanf("%d", &n))
	{
		if (n == 0) return 0;
		for (int i = 1; i <= n; i ++) scanf("%d", a + i);
		int pos = 0, cur = 1, i = 1;
		while (true)
		{
			while (pos > 0 && p[pos - 1] == cur) pos --, cur ++;
			if (i == n + 1 && pos == 0)
			{
				cout << "yes\n";
				break;
			}
			if (i == n + 1 && p[pos - 1] != cur)
			{
				cout << "no\n";
				break;
			}
			if (a[i] == cur) cur ++;
			else
			{
				p[pos ++] = a[i];
			}
			i ++;
		}
	}		
}


