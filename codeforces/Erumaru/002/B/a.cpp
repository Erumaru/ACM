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

string s, t;
int a1, a2;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s >> t;
	if (sz(s) != sz(t))
	{
		cout <<  "NO";
		return 0;
	}           

	for (int i = 0; i < sz(s); i ++)
	{
		if (s[i] == '1') a1 ++;
		if (t[i] == '1') a2 ++;
	}                 

	if (a1 == 0)
	{
		if (a2 == 0) cout << "YES";
		else cout << "NO";
		return 0;
	}

	if (a2 == 0)
	{
		cout << "NO";
		return 0;
	}

	cout << "YES";
}


