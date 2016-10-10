
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

bool vowel(char c)
{
	return c == 'a' || c == 'e' || c == 'u' || c == 'y' || c == 'i' || c == 'o';
}

void yes()
{
	cout << "YES";
	exit(0);
}

void no()
{
	cout << "NO";
	exit(0);
}

int n, h[110], p[110];
string s;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i ++) cin >> p[i];

	getline(cin, s);
	for (int i = 1; i <= n; i ++) 
	{
		getline(cin, s);
		for (int j = 0; j < sz(s); j ++)
		{
			if (vowel(s[j])) h[i] ++;
		}
	}

	//for (int i = 1; i <= n; i ++) cout << i << " " << h[i] << "\n";
	for (int i = 1; i <= n; i ++) if (h[i] != p[i]) no();

	yes();
}


