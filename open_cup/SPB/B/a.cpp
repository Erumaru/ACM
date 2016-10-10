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

int n, a[110], suff[110], p[110][5];

int main ()
{      
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	//sort(a + 1, a + 1 + n, greater<int>());
	for (int i = n; i > 0; i --) suff[i] += suff[i + 1] + a[i];

	int bonus = 0, ans = 0;
	
	for (int i = 1; i <= n; i ++)
	{
		int cur = a[i] / 100;
		for (int j = i + 1; j <= n; j ++)
		{
			if (a[j] <= cur)
			{
				b[j] += a[j];
				a[j] = 0;
			}
		}
		
	}

	cout << ans << "\n";
	for (int i = 1; i <= n; i ++) cout << p[i][1] << " + " << p[i][2] << "\n"; 
}


