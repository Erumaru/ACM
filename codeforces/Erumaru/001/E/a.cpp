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

string s;
ll ans;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	                
	cin >> s;

	for (int i = 0; i < sz(s); i ++)
	{
		if (s[i] == '4' || s[i] == '0' || s[i] == '8') ans ++;
		if (i)
		{
			int cur = (s[i - 1] - '0') * 10 + s[i] - '0';
			//cout << cur << "\n";
			if (cur % 4 == 0)
			{
				ans += (i);
			}
		}
	}

	cout << ans << "\n";
}


