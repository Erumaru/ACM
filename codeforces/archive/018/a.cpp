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

int n;
string s, t;
map <string, string> original, name;

int main ()
{      
	cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> s >> t;
		if (!name.count(s))
		{
			original[s] = t;
			name[t] = s;		
		}
		else
		{
			string cur = name[s];
			original[cur] = t;
			name[t] = cur;
		}
	}	

	cout << sz(original) << "\n";
	for (auto it: original) cout << it.first << " " << it.second << "\n";
}


