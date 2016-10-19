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

int main ()
{      	
	cin >> s;
	if (s[sz(s) - 1] == 'E')
	{
		cout << sz(s) - 1;
		return 0;
	}
	if (s[0] == 'E') 
	{
		cout << 0;
		return 0;
	}	
	

	int id = -1, mx = 0, cnt = 0;
	
	for (int i = sz(s) - 1; i >= 0; i --)
	{
		if (s[i] == 'E')
		{
			cnt ++;
		}
		else 
		{
			if (cnt > mx)
			{
				mx = cnt;
				id = i + 1;
			}
			cnt = 0;
		}
	}

	if (s[id + 1] == 'E') cout << id + 1;
	else cout << id;
}


