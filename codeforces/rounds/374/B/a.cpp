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

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	 
	cin >> n >> k;
	for (int i = 0; i <= n; i ++)
	{
		cin >> str[i];
		arr[i] = str.size();
	}                       

	int t = 0;
	int v = arr[n];   
	sort(str, str + n);

	for (int i = 0; i < n; i ++)
	{
		if (arr[i] > v) break;
		if (n1 == 1) ans1 ++;
		ans2 ++;
		if (t == k)
		{
			t = 0;
			if (n1) ans1 += 5;
			ans2 += 5;
		}
		if (arr[i] == v)
		{
			n1 = 0
		}
		t ++;
	} 
}


