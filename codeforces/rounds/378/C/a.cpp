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

int n, m, a[510], b[510], p[510], d;
char c[510];

void no()
{
	cout << "NO";
	exit(0);
}

int main ()
{     
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) scanf("%d", b + i);

	int j = 1, i = 1;	
	for (i = 1; i <= m; i ++)
	{
		while (j < m && b[i] != a[j])
		{
			if (a[j] > a[j + 1])
			{
				p[d] = j;
			}
		}
		j ++;
		cout << i << " " << j << "\n";
	}
	

	//if (i != n || j != m) no();
	cout << "YES";
	for (i = 1; i < d; i ++)
	{
		cout << p[i] << " " << c[i] << "\n";
	}

}


