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

int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int v[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days[] = {"monday", "tuesday", "wednesday","thursday", "friday", "saturday", "sunday"};
string s, t;
map <string, int> mk;


int main ()
{      
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;
	mk["monday"] = 1;
	mk["tuesday"] = 2;
	mk["wednesday"] = 3;
	mk["thursday"] = 4;
	mk["friday"] = 5;
	mk["saturday"] = 6;
	mk["sunday"] = 7;
	int a = mk[s], b = mk[t];
	//for (int i = 1; i < 12; i ++) v[i] = (v[i - 1] + m[i - 1]) % 7;
	for (int i = 0; i < 11; i ++)
	{
		int ta = a;
		while (m[i] --)
		{
			ta = ta % 7 + 1;
		}
		if (ta == b) 
		{
			cout << " YES ";
			//break;
			//return 0;
		}
		cout << a << " " << ta << "\n";
	}


	//cout << "NO";
	return 0;
}


