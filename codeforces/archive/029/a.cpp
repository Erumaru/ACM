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

int n, d, a, b, x[100100];

int main ()
{      
	cin >> n >> d >> a >> b;
	for (int i = 1; i <= n; i ++) cin >> x[i];

	int k = 1, p = 2, ans = 0;
	for (int i = 2; i <= n; i ++) 
	{
		if (x[i] > x[i - 1])
		{
			if (p != 0) k = 1, p = 0;
			else k ++;
			int cur = min(a * k, d / x[i]);
			//cout << cur << " ";
			ans += cur;
			d -= cur * x[i];
		}
		else if (x[i] < x[i - 1])
		{
			if (p != 1) k = 1, p = 1;
			else k ++;
			int cur = min(b * k, ans);
			ans -= cur;
			//cout << cur << " ";
			d += cur * x[i];
		}
	}	

	cout << d << " " << ans << "\n";
}


