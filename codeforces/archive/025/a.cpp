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


int n, k, dp[600][600], a[600];
int from[600][600];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	for (int i = 0; i <= n; i ++)
	{
		for (int j = 0; j <= 500; j ++) dp[i][j] = inf;
	}
	dp[0][k]=0;
	for (int i = 1; i <= n; i ++)
	{
		for(int j = a[i]; j <= 500; j++){
			for(int t = 0; t <= 500; t++){
				if(dp[i-1][t] + j - a[i] < dp[i][j] && t + j >= k){
					dp[i][j]=dp[i-1][t] + j - a[i];
					from[i][j] = t;
				}
			}
		}	
	}

	int ans = inf;
	int cur = -1;
	for (int i = 0; i <= 500; i ++)
	{
		if(ans > dp[n][i]) {
			ans = min(ans, dp[n][i]);
			cur = i;
		}
	}
	cout << ans<<endl;
	int x =  n;
	while(x > 0){
		a[x] = cur;
		cur = from[x][cur];
		x--;
	}
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	#ifndef ONLINE_JUDGE
        fprintf(stderr, "Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
	return 0;
}