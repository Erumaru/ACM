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

int convert(string s)
{
	int h = (s[0] - '0') * 10 + (s[1] - '0');
	int m = (s[3] - '0') * 10 + (s[4] - '0');
	int ss = (s[6] - '0') * 10 + (s[7] - '0');
	m += h * 60;
	ss += m * 60;
	return ss;
}

int speed(string s)
{
	int res = 0;
	for (int i = 0; i < sz(s); i ++) res = res * 10 + (s[i] - '0');
	return res;	
}

string s;
double cur, ans, temp = 60 * 60;

int main ()
{      
	int prev = 0;
	while (getline(cin, s))	
	{
		if (sz(s) == 8)
		{
			int time = convert(s);
			double delta = time - prev;
			prev = time;
			delta = delta / temp;
			ans += delta * cur;
			printf("%s %.2f km\n", s.c_str(), ans);
		}
		else
		{
			int time = convert(s.substr(0, 8));
			double delta = time - prev;
			prev = time;
			delta = delta / temp;
			ans += delta * cur;
			int newSpeed = speed(s.substr(9));
			cur = newSpeed;
		}
	}
}


