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

string s[] = {"king", "queen", "bishop", "knight", "rook", "pawn"};
string q[] = {"black", "white"};
int p[] = {1, 1, 2, 2, 2, 8};
int tot[5][10], a[5][10], b[5][10], n, m; 
map <string, int> mk;

int main ()
{      
	for (int i = 0; i < 6; i ++) mk[s[i]] = i;
	mk["black"] = 0;
	mk["white"] = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		string t, r;
		cin >> t >> r;
		int ft = mk[t], st = mk[r];
		tot[ft][st] ++;
		a[ft][st] ++;
	}

	for (int i = 1; i <= m; i ++)
	{
		string t, r;
		cin >> t >> r;
		int ft = mk[t], st = mk[r];
		tot[ft][st] ++;
		b[ft][st] ++;
 	}

 	for (int i = 0; i < 2; i ++)
 	{
 		for (int j = 0; j < 6; j ++)
 		{
 			if (tot[i][j] < p[j]) 
 			{
 				cout << "impossible\n";
 				return 0;
 			}
 		}
 	}

 	for(int i = 0; i < 2; i ++)
 	{
 		for (int j = 0; j < 6; j ++)
 		{
 			if (a[i][j] >= p[j]) continue;
 			string pp = q[i], qq = s[j];
 			while (a[i][j] < p[j])
 			{
 				a[i][j] ++;
 				cout << pp << " " << qq << "\n";
 			} 
 		}
 	}
}


