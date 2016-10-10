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

int n, w, a[400010], b[400010], z[400010];

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        

	cin >> n >> w;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < w; i ++) cin >> b[i];
	for (int i = 0; i < n - 1; i ++) a[i] = a[i] - a[i + 1];
	for (int i = 0; i < w - 1; i ++) b[i] = b[i] - b[i + 1];

	b[w - 1] = inf;
	for (int i = 0; i < n - 1; i ++) b[w + i] = a[i];

	n = n + w - 1;
	
	for (int i = 1, j = 0; i < n; i ++)
	{
		if (i < z[j] + j) z[i] = min(z[i - j], z[j] + j - i);
		while (i + z[i] < n && b[z[i]] == b[z[i] + i]) z[i] ++;
		if (i + z[i] > j + z[j]) j = i;
 	}

 	int ans = 0;
 	//for (int i = 0; i < n; i ++) cout << b[i] << " ";
 	//cout << "\n";
 	//for (int i = 0; i < n; i ++) cout << z[i] << " ";
 	//cout << "\n";
 	for (int i = 0; i < n; i ++)
 	{
 		if (z[i] == w - 1) ans ++; 
 	}

 	cout << ans << "\n";
}


