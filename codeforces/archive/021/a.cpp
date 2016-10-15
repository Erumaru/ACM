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
double ans;

int getNext(int pos)
{
	while (s[pos] >= 'a' && s[pos] <= 'z') pos ++;
	return pos;
}

double getnum(string s)
{
	double res = 0;
	int cnt = 0;
	string cur = "";
	bool was = false;
	for (int i = sz(s) - 1; i >= 0; i --)
	{
		if (s[i] == '.') 
		{
			was = true;
			break;
		}
		cnt ++;
		cur += s[i];
	}
	if (cnt == 2 && was)
	{
		double d = (double(s[sz(s) - 2] - '0')) / 10.0 + (double(s[sz(s) - 1] - '0')) / 100.0;
		//cout << d << " ";
		for (int i = 0; i < sz(s) - 2; i ++)
		{
			if (s[i] == '.') continue;
			res = res * 10.0 + (s[i] - '0');
		} 
		res += d;
	}
	else
	{
		for (int i = 0; i < sz(s); i ++)
		{
			if (s[i] == '.') continue;
			res = res * 10.0 + (s[i] - '0');
		}
	}

	return res;
}

int main ()
{      
	cin >> s;
	int n = sz(s);
	int pos = 0;
	while (true)
	{
		//cerr << pos << " ";
		pos = getNext(pos);
		int newpos = pos;
		while (!(s[newpos] >= 'a' && s[newpos] <= 'z') && newpos < n) newpos ++;
		string cur = "";
		for (int i = pos; i < newpos; i ++)
		{
			cur += s[i];
		}

		ans += getnum(cur);
		if (newpos == n) break;
		pos = newpos;
	}

	int ans2 = ans;
	string res = "";
	if (ans2 == 0) res += "0";
	int cnt = 0;
	//cout << ans << " ";
	while (ans2)
	{
		if (sz(res) != 0 && (sz(res) - cnt) % 3 == 0) 
		{
			cnt ++;
			res += ".";
		}
		int d = ans2 % 10;
		ans2 /= 10;
		res += char(d + '0');
	}

	reverse(all(res));
	ans2 = ans;
	ans -= ans2;
	ostringstream strs;
	strs << ans;
	string str = strs.str();
	if (ans != 0.0)
	{
		res += ".";
		int y = 0;
		string g = "";
		for (int i = sz(str) - 1; i >= 0; i --)
		{
			if (str[i] == '.') break;
			g += str[i];
			y ++;
		}
		reverse(all(g));
		for (int i = 0; i < sz(g); i ++) res += g[i];
		if (y == 1) res += "0";
	}
	cout << res << " ";

}


