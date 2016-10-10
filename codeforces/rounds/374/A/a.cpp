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
int n, cnt;
string s;
vector <int> ans;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> s;
	for (int i = 0; i < sz(s); i ++)
	{
		if (s[i] == 'W') 
		{
			if (cnt != 0) ans.pb(cnt);
			cnt = 0;
		}
		else cnt ++;
	}
	if (cnt != 0) ans.pb(cnt);               

	cout << sz(ans) << "\n";
	for (int i = 0; i < ans.size(); i ++) cout << ans[i] << " ";            
}


