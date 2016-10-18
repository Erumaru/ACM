//#include <bits/stdc++.h>
#include <iostream>


using namespace std;

const int inf = (int)(1e9) + 100;
const int mod = (int)(1e9) + 100;
const int N = (int)(2e5) + 100;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vpi vector <pii>
#define vpl vector <pll>
#define sc1(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d%d", &a, &b)
#define frw(i, p, n) for(int i = p; i <= n; i++)
#define bck(i, n, p) for(int i = n; i >= p; i--)
#define mem(a) memset(a, 0, sizeof(a))

ll k, r;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> k >> r;
	int sum = 0, d = 0;
	while (true)
	{
		sum += k;
		d ++;
		sum %= 10;
		if (sum  == r || sum == 0)
		{
			cout << d;
			return 0;
		}
	}	

	#ifndef ONLINE_JUDGE
        fprintf(stderr, "Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
	return 0;
}