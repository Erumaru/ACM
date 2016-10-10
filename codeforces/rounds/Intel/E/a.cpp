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

int n, ans;
string s, st;

string p (int n)
{
	string res = "";
	while (n)
	{
		int d = n % 10;
		n /= 10;
		res += char(d + '0');
	}
	reverse(res.begin(), res.end());
	return res;
}

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> s;
	if (n == 24)
	{
		for (int i = 0; i < 24; i ++)
		{
			for (int j = 0; j < 60; j ++)
			{
				string t = "";
				if (i < 10) t += "0";
				t += p(i);
				t += ":";
				if (j < 10) t += "0";
				t += p(j);
				int cur = 0;
				for (int k = 0; k < 5; k ++)
				{
					if (t[k] != s[k]) cur ++;
				}
				if (cur < ans)
				{
					ans = cur;
					st = t;
				}
			}
		}
	}
	else
	{
		for (int i = 1; i <= 12; i ++)
		{
			for (int j = 0; j < 60; j ++)
			{
				string t = "";
				if (i < 10) t += "0";
				t += p(i);
				t += ":";
				if (j < 10) t += "0";
				t += p(j);
				int cur = 0;
				for (int k = 0; k < 5; k ++)
				{
					if (t[k] != s[k]) cur ++;
				}
				if (cur < ans)
				{
					ans = cur;
					st = t;
				}
			}
		}	
	}

	cout << st << " ";

}


