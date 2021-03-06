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

int ans = 0;
string s;

__int128 a;

bool vowel(char c)
{
	return c == 'A' || c == 'U' || c == 'E' || c == 'Y' || c == 'I' || c == 'O';
}

int main ()
{      
	cin >> s;
	s = " " + s;
	s += "A";
	int prev = 0;
	for (int i = 1; i < sz(s); i ++)
	{
		if (vowel(s[i]))
		{
			ans = max(i - prev, ans);
			prev = i;
		}
	}

	cout << ans;
}


