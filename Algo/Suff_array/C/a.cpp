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
#define sz(n) ll(n.size())
#define all(n) n.begin(), n.end()


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5 + 123;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

string A, B, s;
ll suff[50010], nsuff[50010], col[50010], ncol[50010], 
head[50010], lcp[50010], p[50010], len[50010], nxt[100010], k[100010];

bool cmp(int i, int j)
{
	return s[i] < s[j];
}

void calc()
{
	int n = sz(s);

	for (int i = 0; i < n; i ++) suff[i] = i;
	sort(suff, suff + n, cmp);

	int cn = 0;
	for (int i = 0; i < n; i ++)
	{
		if (i == 0 || s[suff[i]] != s[suff[i - 1]])
		{
			col[suff[i]] = cn;
			head[cn] = i;
			cn ++; 
		}
		else col[suff[i]] = cn - 1;
	}

	for (int len = 1; len <= n; len *= 2)
	{
		for (int i = 0; i < n; i ++)
		{
			int pos = suff[i] - len;
			if (pos < 0) pos += n;
			nsuff[head[col[pos]]] = pos;
			head[col[pos]] ++;
 		}

 		for (int i = 0; i < n; i ++) suff[i] = nsuff[i];

 		cn = 0;

 		for (int i = 0; i < n; i ++)
 		{
 			if (i == 0 || col[suff[i]] != col[suff[i - 1]] 
 				|| col[(suff[i] + len) % n] != col[(suff[i - 1] + len) % n])
 			{
 				ncol[suff[i]] = cn;
 				head[cn] = i;
 				cn ++;
 			}
 			else ncol[suff[i]] = cn - 1;
 		}

 		for (int i = 0; i < n; i ++) col[i] = ncol[i];
  	}

  	n --;
  	s.erase(n);
  	for (int i = 0; i < n; i ++) suff[i] = suff[i + 1];

  	for (int i = 0; i < n; i ++) p[suff[i]] = i;

  	int len = 0;
  	for (int i = 0; i < n; i ++)
  	{
  		int pos = p[i];
  		if (pos == n - 1)
  		{
  			lcp[pos] = 0;
  			len = 0;
  			continue;
  		}
  		len = max(len - 1, 0);
  		while (i + len < n && suff[pos + 1] + len < n &&
  			s[suff[pos] + len] == s[suff[pos + 1] + len]) len ++;
  		lcp[pos] = len;
  	}
  	
  	/*for (int i = 0; i < n; i ++)
  	{
  		for (int j = suff[i]; j < n; j ++) cout << s[j];
  			cout << "\n";
  	}

  	for (int i = 0; i < n; i ++) cout << lcp[i] << " ";
	*/
}

int get(int x)
{
	x = suff[x];
	if (x < sz(A)) return 0;
	return 1;
}

vector <int> zf(const string &s)
{
	int n = sz(s);
	vector <int> z(n);
	for (int i = 1, j = 0; i < n; i ++)
	{
		if (i < j + z[j]) z[i] = min(z[i - j], j + z[j] - i);
		while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i] ++;
		if (i + z[i] > z[j] + j) j = i;
	}
	return z;
}

int getNext(int x)
{
	if  (x >= sz(A) || x < 0) return -1;
	x = nxt[x + sz(B) + 1] - sz(B) - 1;
	if  (x >= sz(A) || x < 0) return -1;
	return x;
}

void solve(int test)
{
	cin >> A >> B;
	s = A + "#";
	calc();
	s = B + "#" + A;
	vector <int> z = zf(s);
	int n = sz(s);

	for (int i = 0; i < n; i ++) k[i] = 0;

	for (int i = 0; i < n; i ++)
	{
		if (z[i] == sz(B)) k[i + sz(B) - 1] = 1;
	}

	for (int i = n - 1; i >= 0; i --)
	{
		if (k[i]) nxt[i] = i;
		else nxt[i] = nxt[i + 1];
	}
	n = sz(A);
	//cout << "\n";
	ll ans = 0;
	//for (int i = 0; i < n; i ++) cout << i << ": " << getNext(i) << "\n";

	int g = getNext(suff[0] + sz(B) - 1);
	if (g == -1 || g >= suff[0])
	{
		if (g == -1) g = n;
		ans += g - suff[0];
	}

	for (int i = 0; i < n - 1; i ++)
	{
		//cout << i << " " << suff[i + 1] << " " << getNext(suff[i + 1] + sz(B) - 1) << " " 
		//<< lcp[i] << "\n";
		if (getNext(suff[i + 1] + sz(B) - 1) != -1 && getNext(suff[i + 1] + sz(B) - 1) < suff[i + 1] + lcp[i]) 
		{
		//	cout << "+ \n";
			continue;
		}
		ll cur = getNext(suff[i + 1] + max(lcp[i], sz(B) - 1));
		if (cur == -1) cur = n;
		ans += cur - (suff[i + 1] + lcp[i]);
		//cout << cur << " " << cur - (suff[i + 1] + lcp[i])<< " \n";
	}

	printf("Case %d: %lld\n", test, ans);
}

int test;

int main ()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);        


	cin >> test;
	for (int i = 1; i <= test; i ++) solve(i);
}


