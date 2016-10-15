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
string s;

int main ()
{      
	cin >> s;
	int n = sz(s);
	int balance = 0, ans = 0;
	for (int i = 0; i < n; i ++)
	{
		if (s[i] == 'g')
		{
			if (balance > 0)
			{
				ans ++;
				balance --;
			}
			else balance ++;
		}
		else
		{	
			if (balance > 0) balance --;
			else 
			{
				ans --;
				balance ++;
			}
		}
	}

	cout << ans << "\n";
}


