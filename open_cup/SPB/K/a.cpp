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
bool p[5001000];

int get(const string &s, int x, int y)
{
	int n = sz(s);
	int res = 0;
	for (int i = x; i <= y; i ++)
	{
		res = res * 10 + (s[i] - '0');
	}
	//cout << res << " ";
	return res;
}

string ts(int x)
{
	string res = "";
	while (x)
	{
		int d = x % 10;
		x /= 10;
		res += char(d + '0');
	}
	reverse(all(res));
	return res;
}


bool check(int x)
{
	string pp = ts(x);
	int n = sz(pp);
	//cout << pp << ": ";
	for (int i = 0; i < n; i ++)
	{
		for (int j = i; j < n; j ++)
		{
			if (p[get(pp, i, j)]) 
			{
				//cout << "bad\n";
				return false;
			}
		}
	}
	//cout << "good\n";
	return true;
}

int main ()
{      
	cin >> n;
	int cur = 1;
	p[0] = true;
	p[1] = true;
	if (n >= 10) 
	{
		cout << -1;
		return 0;
	}
	for (int i = 2; i <= 500; i ++)
	{
		if (!p[i])
		{
			for (int j = i + i; j <= 500; j += i) p[j] = true;
		}
	}
	int cnt = 0;
	while (true)
	{
		if (cnt == n) 
		{
			cout << cur << "\n";
			return 0;
		}
		cur ++;
		if (cur > 5000000) 
		{
			cout << -1;
			return 0;
		}
		cnt += check(cur);
	}
}


